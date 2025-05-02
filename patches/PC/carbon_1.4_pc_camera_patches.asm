; 
; Carbon PC v1.4 America - Debug Camera Restoration
; Tested with the VITALITY executable, should work with the original too
; as long as it's injected after it gets unpacked
;
; May work with v1.3 as well, I haven't checked the offsets, but a lot of them are identical.
;
; CameraAI::Director::mInputQ offset : 0x1C
; Hook the new code at : 0x00490FCC
; Result of Attrib::StringHash32("CDActionDebug") : 0x578e1c8c
; Result of Attrib::StringHash64("CDActionDebug") : 0x7c6223f4794eb9cb
; CAMERAACTION_DEBUG : 0x25
;
; ActionQueue function locations:
; ActionQueue::IsEmpty   : 0x00680310
; ActionQueue::GetAction : 0x00680350
; ActionQueue::PopAction : 0x00680320
;

;
; Where we inject, `esi` is the `this` pointer.
; We can freely alter the following registers: `eax, ecx, edx` (more to be added, perhaps)
;
new_camera_code:
    nop ; Not needed, but leads to cleaner disassembly
.check_if_empty:
    lea     ecx, [esi + 0x1C] ; Get the address of the action queue (mInputQ), store it in ecx
    call    0x00680310 ; IsEmpty
    cmp     eax, 1
    je      .return_to_original_code ; If we're empty, just return to the original code.

    ; Otherwise, we can get the action.
    
    

    ; `this` is passed in `ecx`, and the return value needs to be passed in the stack
    lea     ecx, [esi + 0x1C] ; mInputQ
    lea     eax, [esp + 0x10] ; Stack variable, unused, so it should be fine...
    push    eax
    call    0x00680350 ; GetAction
    mov     ecx, [esp + 0x10]

    ; eax is now ActionData*
    mov     eax, [ecx]
    

    ; eax now holds the current action id.
    cmp     eax, 0x25 ; CAMERAACTION_DEBUG
    jne     .pop_action

    ; Write to 0x10 and 0x14.
    ; 0x10 : Hash (uint32)
    ; 0x14 : Address of the string (char*)
    mov     dword ptr [esi + 0x10], 0x578E1C8C
    mov     dword ptr [esi + 0x14], 0x009C7EFC ; address of "CDActionDebug"
    
    ; Okay! We're done here, we just need to pop the action (until the queue's empty), then we can return.

.pop_action:
    lea     ecx, [esi + 0x1C] ; mInputQ
    call    0x00680320 ; PopAction
    jmp     .check_if_empty


.return_to_original_code:
    ; Return to the original code.
    mov     ecx, [esi + 0x18] ; Instruction we replaced
    cmp     ecx, ebx
    jmp     0x00490FD1 ; And now, jump back
