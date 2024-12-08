;IJ Roy
data segment
    a dw 1055h
    b dw 0041h
    subtraction dw ?
    borrow db 00h
data ends
code segment
    assume cs:code,ds:data
    start:
    mov ax,data
    mov ds,ax
    mov ax,a
    sub ax,b
    jnc skip
    inc borrow
    skip: mov subtraction,ax
    mov ah,4h
    int 21h
    code ends
end start
