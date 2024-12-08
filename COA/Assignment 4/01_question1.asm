
;IJ Roy

data segment
    a db 0C1h
    b db 0B1h
    sum db ?
    carry db 00h
data ends
code segment
    assume cs:code,ds:data
    start:
    MOV ax,data
    mov ds,ax
    mov al,a
    add al,b
    jnc skip
    inc carry
    skip:mov sum,al
    mov ah,4ch
    int 21h
    code ends
end start