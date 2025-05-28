# 
# Carbon PlayStation 2 CE America - Debug Camera Restoration
#
# CameraAI::Director::mInputQ offset : 0x1C
# Hook the new code at : 0x0018048C
# Result of Attrib::StringHash32("CDActionDebug") : 0x578e1c8c
# Result of Attrib::StringHash64("CDActionDebug") : 0x7c6223f4794eb9cb
# CAMERAACTION_DEBUG : 0x25
#
# ActionQueue function locations:
# ActionQueue::IsEmpty   : 0x0037bcf8
# ActionQueue::GetAction : 0x0037bf60
# ActionQueue::PopAction : 0x0037beb8
#
.set noreorder

# ReadBuildVersionScript address : 0x00387798

# We inject at 0x0018048C
# 00180488:  lw       $a2, 0x18($s2)
# 0018048C:  beq      $a2, $zero, LAB_00180510     # <-- replace this branch
# 00180490:  addiu    $s1, $s2, 0x10               # <-- delay slot (keep it as is)

# mips64r5900el-ps2-elf-as -O0 -mabi=eabi -64 carbon_ps2_us_camera_patches.asm -o carbon_ps2_us_camera_patches.elf

#
# Where we inject, `$s2` is the `this` pointer.
# We can freely alter the following registers: `$v0, $v1, $a0, $a1` (more to be added, perhaps)
#
new_camera_code:
    nop # Not needed, but leads to cleaner disassembly
.check_if_empty:
    jal     0x0037bcf8 # IsEmpty
    addiu   $a0, $s2, 0x1C # Get the address of the action queue (mInputQ), store it in $a2
    
    # if ($v0 != 0)
    #   goto .return_to_original_code;
    bne     $v0, $zero, .return_to_original_code
    nop # If we're empty, just return to the original code.

    # Otherwise, we can get the action.
    

    # `this` is passed in `$a0`, and the return value (ActionRef) is in $v0
    jal     0x0037bf60 # GetAction
    addiu   $a0, $s2, 0x1C # mInputQ

    # NOTE: Technically, this *could* be a NULL pointer.
    # Chances of that happening are probably rather low, but game code normally checks for that.
    # We don't, though. Just so you know.

    # $v0 is now ActionData*
    lw      $v1, 0x00($v0)
    
    # $v1 now holds the current action id.

    # $v0 = 0x25;
    # if ($v1 != $v0 /* 0x25 */)
    #   goto .pop_action;
    li      $v0, 0x25 # CAMERAACTION_DEBUG
    bne     $v1, $v0, .pop_action

    # Write to 0x10 and 0x14.
    # 0x10 : Hash (uint32)
    # 0x14 : Address of the string (char*)

    # These `li` instructions here are pseudo-instructions
    # It actually assembles to:
    # lui   $v0, 0x578E
    # ori   $v0, $v0, 0x1C8C

    li      $v0, 0x578E1C8C
    sw      $v0, 0x10($s2)
    li      $v0, 0x00576f78 # address of "CDActionDebug"
    sw      $v0, 0x14($s2)
    
    # Okay! We're done here, we just need to pop the action (until the queue's empty), then we can return.

.pop_action:
    jal     0x0037beb8 # PopAction
    addiu   $a0, $s2, 0x1C # mInputQ
    j       .check_if_empty
    nop


.return_to_original_code:
    # Return to the original code.

    # We reload $a2 just to be sure. (and it gives us an extra register)
    # The original code loads $a2 in two different places,
    # but this is more convenient to patch.

    # if ($a2 == 0)
    #   goto 0x00180510;
    # else
    #   goto 0x00180494;

    # We don't need to reload $a2 here, but to be sure:
    lw      $a2, 0x18($s2)
    beq     $a2, $zero, LAB_00180510 # if $a2 is 0, jump to 0x00180510
    nop

    j       0x00180494 # otherwise, we jump to 0x00180494 (continue execution as normal)
    nop

    # The assembler can't calculate a direct branch, so we need to do this instead...
LAB_00180510:
    j       0x00180510
    nop
