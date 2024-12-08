;IJ Roy
data segment
    a_h dw 0000h
    a_l dw 1011h       
    b dw 0001h       
    quotient dw ?    
    remainder dw ?   
data ends

code segment
    assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

    mov dx, a_h     
    mov ax, a_l        
    mov bx, b         
    div bx             
    mov quotient, ax   
    mov remainder, dx  

    mov ah, 4ch       
    int 21h

code ends
end start
