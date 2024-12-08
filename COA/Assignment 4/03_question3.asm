
;IJ Roy

data segment
    a db 55h
    b db 41h
    subtraction db ?
    borrow db 00h
data ends
code segment
    assume cs:code,ds:data
    start:
    mov ax,data
    mov ds,ax
    mov al,a
    sub al,b
    jnc skip
    inc borrow
    skip: mov subtraction,al
    mov ah,4ch
    int 21h
    code ends
end start