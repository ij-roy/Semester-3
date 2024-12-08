;IJ Roy
data segment
    a dw 0001h
    b dw 0002h
    productlow dw ?
    producthigh dw ?    
data ends
code segment
    assume cs:code,ds:data
    start:
    mov ax,data
    mov ds,ax
    mov ax,a
    mov bx,b
    mul bx
    mov productlow,ax
    mov producthigh,dx
    mov ah,4Ch
    int 21h
code ends
end start
