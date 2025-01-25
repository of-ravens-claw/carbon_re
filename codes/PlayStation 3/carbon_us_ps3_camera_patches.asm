# 
# Carbon PlayStation 3 America - Debug Camera Restoration
#
# CameraAI::Director::mInputQ offset : 0x1C
# Hook the new code at : 0x000dbf24
# Result of Attrib::StringHash32("CDActionDebug") : 0x578e1c8c
# Result of Attrib::StringHash64("CDActionDebug") : 0x7c6223f4794eb9cb
# CAMERAACTION_DEBUG : 0x25
#
# ActionQueue function locations:
# ActionQueue::IsEmpty   : 0x003bfaac
# ActionQueue::GetAction : 0x003acd58
# ActionQueue::PopAction : 0x003bfac0
# TOC for all of them: 0x0093cfe8 (Primary TOC, same one used by the function we cave, and the one we place new code at.)
#

#
# We're placing our new code at 0x003fa6bc.
# This is ReadBuildVersionScript + 4, we replace 0x003fa6b8 with the blr instruction, and then we can do whatever we want with the remaining bytes. 
#
# Where we inject, `r31` is the `this` pointer.
# We can freely alter the following registers: `r3, r4, r9, r11` (more to be added, perhaps)
#
new_camera_code:
    nop # Not needed, but leads to cleaner disassembly
.check_if_empty:
    addi    r3, r31, 0x1C # Get the address of the action queue (mInputQ), store it in r3
    bl      0x003bfaac # IsEmpty
    cmplwi  r3, 1
    beq     .return_to_original_code # If we're empty, just return to the original code.

    # Otherwise, we can get the action.
    
    # `this` is passed in `r4`, and the return value needs to be passed in `r3`
    addi    r3, r1, 0x88 # Stack variable, unused, so it should be fine...
    addi    r4, r31, 0x1C # mInputQ
    bl      0x003acd58 # GetAction
    lwz     r11, 0x88(r1)

    # r11 is now ActionData*
    lwz     r9, 0x00(r11) # Get the id

    # r9 now holds the current action id.
    cmplwi  r9, 0x25 # CAMERAACTION_DEBUG
    bne     .pop_action

    # Write to 0x10 and 0x14.
    # 0x10 : Hash (uint32)
    # 0x14 : Address of the string (char*)
    lis     r3, 0x578E
    ori     r3, r3, 0x1C8C
    stw     r3, 0x10(r31)

    # TODO: Adjust this for the PS3 needing TOC
    # 0x10002b28 - address of "CDActionDebug"
    # 0x00936e68 - TOC entry of "CDActionDebug" (pointer to it)
    # EDIT: Do we need to bother with that?
    lis     r3, 0x1000
    ori     r3, r3, 0x2B28
    stw     r3, 0x14(r31)
    
    # Okay! We're done here, we just need to pop the action (until the queue's empty), then we can return.

.pop_action:
    addi    r3, r31, 0x1C # mInputQ
    bl      0x003bfac0 # PopAction
    b       .check_if_empty


.return_to_original_code:
    # Return to the original code.
    lwz     r4, 0x18(r31) # Instruction we replaced
    b       0x000dbf28 # And now, jump back