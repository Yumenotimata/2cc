global main
main:
    push rbp
    mov rbp,rsp
    sub rsp,64
    mov rax,23
    mov QWORD[rbp-8],1
    mov rax,QWORD[rbp-8]
    push rax
    pop rbx
    mov rsp,rbp
    pop rbp
    ret
