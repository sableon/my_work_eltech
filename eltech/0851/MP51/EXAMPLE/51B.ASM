maska equ 0aah
        ORG     00
        JMP     100H
 ; external interupts
        ORG     03
        PUSH    PSW
        MOV     PSW,#18h  ;select bank1
        sjmp     goon
;timer interupts
        ORG     0Bh
        push psw
        push acc            ; save intrrupted program
        mov     psw, 90h       ; select bank 2, clr C
        jmp     timer_subr
;serial port
        ORG     23H
         push psw
        push acc            ; save intrrupted program
        mov  a,sbuf
        jb   acc.7,dir_cod
         cpl  a
         orl   a,#80h
dir_cod:         mov  p1,a
         CLR     RI
         pop     acc         ; restore and exit
        pop     psw
        RETI
goon:   push acc
        mov  a,p2
        anl  a, r0
        jz     nothing
        mov a,r0
        cpl    a
        mov    r0,a

nothing:        pop  acc
        POP     PSW
        RETI

timer_subr:
         mov     a,r1
        subb      a,#14h
        jnz      near
        mov  r1, 0ffh
near:   inc     r1
        mov     p0,r1
        pop     acc         ; restore and exit
        pop     psw
        RETI


; main program
        ORG     100H
        mov     sp,#50h   ; stack location
        MOV     PSW,#00          ; select bank 0
        MOV     TH0,#0d0H
        MOV     TL0,#0d0H
        MOV     TMOD,#22H    ;prepare timer
        mov      scon,#50h  ; prepare serial port
        SETB    TR0
        MOV     IE,#8bH     ; interupt enable
        mov     11h,#00      ; initial value for meander-> r1 of bank 2
        mov     08,#maska   ; to be used in extern. intr subroutine
M:     MOV     A,#00         ; main program
        MOV     R0,#10H
        ADD     A,#05
        ADD     A,@R0
        ADD     A,R1
        ADD     A,R2
        SJMP    M
        END
