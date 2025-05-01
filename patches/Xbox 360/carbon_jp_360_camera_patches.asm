# 
# Carbon Xbox 360 Japan - Debug Camera Restoration
#
# CameraAI::Director::mInputQ offset : 0x1C
# Hook the new code at : 0x821AFFB8
# Result of Attrib::StringHash32("CDActionDebug") : 0x578e1c8c
# Result of Attrib::StringHash64("CDActionDebug") : 0x7c6223f4794eb9cb
# CAMERAACTION_DEBUG : 0x25
#
# ActionQueue function locations:
# ActionQueue::IsEmpty   : 0x824472E0
# ActionQueue::GetAction : 0x824474E8
# ActionQueue::PopAction : 0x82447428
#

#
# We're placing our new code at 0x82455D64.
# This is ReadBuildVersionScript + 4, we replace 0x82455D60 with the blr instruction, and then we can do whatever we want with the remaining bytes. 
#
# Where we inject, `r31` is the `this` pointer.
# We can freely alter the following registers: `r3, r4, r10, r11` (more to be added, perhaps)
# We can probably use `r2` if we need it, since the Xbox 360 does not use TOC.
#
new_camera_code:
    nop # Not needed, but leads to cleaner disassembly
.check_if_empty:
    addi    r3, r31, 0x1C # Get the address of the action queue (mInputQ), store it in r3
    bl      0x824472E0 # IsEmpty
    cmplwi  r3, 1
    beq     .return_to_original_code # If we're empty, just return to the original code.

    # Otherwise, we can get the action.
    
    # `this` is passed in `r4`, and the return value needs to be passed in `r3`
    addi    r3, r1, 0x50 # Stack variable, unused, so it should be fine...
    addi    r4, r31, 0x1C # mInputQ
    bl      0x824474E8 # GetAction
    lwz     r11, 0x50(r1)

    # r11 is now ActionData*
    lwz     r10, 0x00(r11) # Get the id

    # r10 now holds the current action id.
    cmplwi  r10, 0x25 # CAMERAACTION_DEBUG
    bne     .pop_action

    # Write to 0x10 and 0x14.
    # 0x10 : Hash (uint32)
    # 0x14 : Address of the string (char*)
    lis     r3, 0x578E
    ori     r3, r3, 0x1C8C
    stw     r3, 0x10(r31)

    # 0x8206c6b4 - address of "CDActionDebug"
    lis     r3, 0x8206 # Note: Ghidra is silly, so use -0x7dfa instead.
    ori     r3, r3, 0xC6B4
    stw     r3, 0x14(r31)
    
    # Okay! We're done here, we just need to pop the action (until the queue's empty), then we can return.

.pop_action:
    addi    r3, r31, 0x1C # mInputQ
    bl      0x82447428 # PopAction
    b       .check_if_empty


.return_to_original_code:
    # Return to the original code.
    lwz     r4, 0x18(r31) # Instruction we replaced
    b       0x821AFFBC # And now, jump back