#
#  _   _   ___   ___     _____   _  _   ___      ___   ___    ___   _  __   ___       ___    ___    ___    ___     ___   _  _   ___   _____   ___     _     ___  
# | | | | / __| | __|   |_   _| | || | | __|    / __| | __|  / __| | |/ /  / _ \     / __|  / _ \  |   \  | __|   |_ _| | \| | / __| |_   _| | __|   /_\   |   \ 
# | |_| | \__ \ | _|      | |   | __ | | _|    | (_ | | _|  | (__  | ' <  | (_) |   | (__  | (_) | | |) | | _|     | |  | .` | \__ \   | |   | _|   / _ \  | |) |
#  \___/  |___/ |___|     |_|   |_||_| |___|    \___| |___|  \___| |_|\_\  \___/     \___|  \___/  |___/  |___|   |___| |_|\_| |___/   |_|   |___| /_/ \_\ |___/ 
#
# Seriously, just use the Gecko code instead.

# 
# Carbon Wii America - Debug Camera Restoration
#
# CameraAI::Director::mInputQ offset : 0x1C
# Hook the new code at : 0x8008f078
# Result of Attrib::StringHash32("CDActionDebug") : 0x578e1c8c
# Result of Attrib::StringHash64("CDActionDebug") : 0x7c6223f4794eb9cb
# CAMERAACTION_DEBUG : 0x25
#
# ActionQueue function locations:
# ActionQueue::IsEmpty   : 0x8028bb8c
# ActionQueue::GetAction : 0x8028bdcc
# ActionQueue::PopAction : 0x8028bd48
#

#
# We're placing our new code at 0x80293be8.
# This is ReadBuildVersionScript + 4, we replace 0x80293be4 with the blr instruction, and then we can do whatever we want with the remaining bytes. 
#
# Where we inject, `r31` is the `this` pointer.
# We can freely alter the following registers: `r0, r3, r4, r12` (more to be added, perhaps)
#
new_camera_code:
    nop # Not needed, but leads to cleaner disassembly
.check_if_empty:
    addi    r3, r31, 0x1C # Get the address of the action queue (mInputQ), store it in r3
    bl      0x8028bb8c # IsEmpty
    cmplwi  r3, 1
    beq     .return_to_original_code # If we're empty, just return to the original code.

    # Otherwise, we can get the action.
    
    # This function is really odd on the Wii....
    # It seems to return ActionData*, despite the fact that it really should return ActionRef....
    # This could be an optimization of some kind, I suppose...
    addi    r3, r31, 0x1C # mInputQ
    bl      0x8028bdcc # GetAction

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

    # 0x80566F28 - address of "CDActionDebug"
    lis     r3, 0x8056
    ori     r3, r3, 0x6F28
    stw     r3, 0x14(r31)
    
    # Okay! We're done here, we just need to pop the action (until the queue's empty), then we can return.

.pop_action:
    addi    r3, r31, 0x1C # mInputQ
    bl      0x8028bd48 # PopAction
    b       .check_if_empty


.return_to_original_code:
    # Return to the original code.
    lwz     r4, 0x18(r31) # Instruction we replaced
    b       0x8008f07c # And now, jump back
