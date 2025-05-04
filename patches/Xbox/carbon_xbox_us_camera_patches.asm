; 
; Carbon Xbox America - Debug Camera Restoration
;
; CameraAI::Director::mInputQ offset : 0x1C
; Hook the new code at : 0x00073333
; Result of Attrib::StringHash32("CDActionDebug") : 0x578e1c8c
; Result of Attrib::StringHash64("CDActionDebug") : 0x7c6223f4794eb9cb
; CAMERAACTION_DEBUG : 0x25
;
; ActionQueue function locations:
; ActionQueue::IsEmpty   : 0x001D00A0
; ActionQueue::GetAction : 0x001D00E0
; ActionQueue::PopAction : 0x001D00B0
;

; ReadBuildVersionScript address : 0x001dbb40

;
; Where we inject, `esi` is the `this` pointer.
; We can freely alter the following registers: `eax, ecx, edx` (more to be added, perhaps)
;
new_camera_code:
    nop ; Not needed, but leads to cleaner disassembly
.check_if_empty:
    lea     ecx, [esi + 0x1C] ; Get the address of the action queue (mInputQ), store it in ecx
    call    0x001D00A0 ; IsEmpty
    cmp     eax, 1
    je      .return_to_original_code ; If we're empty, just return to the original code.

    ; Otherwise, we can get the action.
    
    

    ; `this` is passed in `ecx`, and the return value needs to be passed in the stack
    lea     ecx, [esi + 0x1C] ; mInputQ
    lea     eax, [esp + 0x10] ; Stack variable, unused, so it should be fine...
    push    eax
    call    0x001D00E0 ; GetAction
    mov     ecx, dword ptr [esp + 0x10] ;

    ; NOTE: Technically, this *could* be a NULL pointer.
    ; Chances of that happening are probably rather low, but game code normally checks for that.
    ; We don't, though. Just so you know.

    ; ecx is now ActionData*
    mov     eax, dword ptr [ecx]
    

    ; eax now holds the current action id.
    cmp     eax, 0x25 ; CAMERAACTION_DEBUG
    jne     .pop_action

    ; Write to 0x10 and 0x14.
    ; 0x10 : Hash (uint32)
    ; 0x14 : Address of the string (char*)
    mov     dword ptr [esi + 0x10], 0x578E1C8C
    mov     dword ptr [esi + 0x14], 0x003A8728 ; address of "CDActionDebug"
    
    ; Okay! We're done here, we just need to pop the action (until the queue's empty), then we can return.

.pop_action:
    lea     ecx, [esi + 0x1C] ; mInputQ
    call    0x001D00B0 ; PopAction
    jmp     .check_if_empty


.return_to_original_code:
    ; Return to the original code.
    mov     ecx, dword ptr [esi + 0x18] ; Instruction we replaced
    cmp     ecx, ebx
    jmp     0x00073338 ; And now, jump back
