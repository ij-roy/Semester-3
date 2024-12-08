
;IJ Roy

data segment
    a dw 1234h
    b dw 4567h
    sum dw ?
    carry db 00h
data ends
code segment
    assume cs:code,ds:data
    start:
    mov ax,data
    mov ds,ax
    mov ax,a
    add ax,b
    jnc skip
    inc carry
    skip: mov sum,ax
    mov ah,4ch
    int 21h
    code ends
end start
