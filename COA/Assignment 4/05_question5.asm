;IJ Roy
data segment
    a db 08h
    b db 09h
    product dw ?
data ends
code segment
    assume cs:code,ds:data
    start:
    mov ax,data
    mov ds,ax
    mov al,a
    mov bl,b
    mul bl 
    mov product,ax
    mov ah,4Ch
    int 21h
    code ends
end start
