global main
main:
    mov rbp,rsp
    mov BYTE[rbp-1],23
    mov al,BYTE[rbp-1]
    ret