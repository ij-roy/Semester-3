;IJ Roy
 data segment
    a dw 0014h       
    b db 10h       
    quotient db ?    
    remainder db ?   
data ends
code segment
    assume cs:code, ds:data
start:
    mov ax, data
    mov ds, ax
    mov ax, a       
    mov bl, b       
   div bl         
    mov quotient, al
    mov remainder, ah
    mov ah, 4ch    
    int 21h
code ends
end start
