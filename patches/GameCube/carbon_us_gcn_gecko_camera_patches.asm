# 
# Carbon GameCube America - Debug Camera Restoration
#
# CameraAI::Director::mInputQ offset : 0x1C
# Hook the new code at : 0x80082668
# Result of Attrib::StringHash32("CDActionDebug") : 0x578e1c8c
# Result of Attrib::StringHash64("CDActionDebug") : 0x7c6223f4794eb9cb
# CAMERAACTION_DEBUG : 0x25
#
# ActionQueue function locations:
# ActionQueue::IsEmpty   : 0x80276bf0
# ActionQueue::GetAction : 0x80276e5c
# ActionQueue::PopAction : 0x80276da4
#

# One difference compared to 'normal' code injection is that we can't use `bl` to call functions.
# Instead, we need to do something like this: (just like we would do for vtables)
#
# lis     r12, 0xDEAD        # upper part of the value
# ori     r12, r12, 0xBEEF   # lower part of the value
# mtctr   r12                # Move r12 to Count Register
# bctrl                      # Branch to Count Register and Link
#
# We use r12 because of ABI reasons. I don't want to bother explaining

#
# Where we inject, `r31` is the `this` pointer.
# We can freely alter the following registers: `r0, r3, r11, r12`
#
new_camera_code:

.check_if_empty:
    addi    r3, r31, 0x1C # Get the address of the action queue (mInputQ), store it in r3
    lis     r12, 0x8027
    ori     r12, r12, 0x6bf0 # IsEmpty
    mtctr   r12
    bctrl
    cmplwi  r3, 1
    beq     .return_to_original_code # If we're empty, just return to the original code.

    # Otherwise, we can get the action.
    
    addi    r3, r1, 0x8 # Stack variable, unused, so it should be fine...
    addi    r4, r31, 0x1C # mInputQ
    lis     r12, 0x8027
    ori     r12, r12, 0x6e5c # GetAction
    mtctr   r12
    bctrl
    lwz     r3, 0x8(r1)

    # r3 is now ActionData*
    lwz     r0, 0x00(r3) # Get the id

    # NOTE: Technically, this *could* be a NULL pointer.
    # Chances of that happening are probably rather low, but game code normally checks for that.
    # We don't, though. Just so you know.

    # r0 now holds the current action id.
    cmplwi  r0, 0x25 # CAMERAACTION_DEBUG
    bne     .pop_action

    # Write to 0x10 and 0x14.
    # 0x10 : Hash (uint32)
    # 0x14 : Address of the string (char*)
    lis     r3, 0x578E
    ori     r3, r3, 0x1C8C
    stw     r3, 0x10(r31)

    # 0x804af888 - address of "CDActionDebug"
    lis     r3, 0x804a
    ori     r3, r3, 0xf888
    stw     r3, 0x14(r31)
    
    # Okay! We're done here, we just need to pop the action (until the queue's empty), then we can return.

.pop_action:
    addi    r3, r31, 0x1C # mInputQ
    lis     r12, 0x8027
    ori     r12, r12, 0x6da4 # PopAction
    mtctr   r12
    bctrl
    b       .check_if_empty


.return_to_original_code:
    # Return to the original code.
    lwz     r11, 0x18(r31) # Instruction we replaced
    # The Gecko code handler will automatically jump back for us.


# For convenience, here is the assembled Gecko code:
# C2082668 00000010
# 387F001C 3D808027
# 618C6BF0 7D8903A6
# 4E800421 28030001
# 4182005C 38610008
# 389F001C 3D808027
# 618C6E5C 7D8903A6
# 4E800421 80610008
# 80030000 28000025
# 4082001C 3C60578E
# 60631C8C 907F0010
# 3C60804A 6063F888
# 907F0014 387F001C
# 3D808027 618C6DA4
# 7D8903A6 4E800421
# 4BFFFF90 817F0018
# 60000000 00000000
