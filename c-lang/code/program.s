	.file	"program.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Hello Hi Welcome to C\0"
	.text
	.globl	greet
	.def	greet;	.scl	2;	.type	32;	.endef
	.seh_proc	greet
greet:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	puts
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "%04d-%02d-%02dT%02d:%02d:%02d\12\0"
	.text
	.globl	displayCurrentDate
	.def	displayCurrentDate;	.scl	2;	.type	32;	.endef
	.seh_proc	displayCurrentDate
displayCurrentDate:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	time
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	localtime
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %r8d
	movq	-8(%rbp), %rax
	movl	4(%rax), %ecx
	movq	-8(%rbp), %rax
	movl	8(%rax), %edx
	movq	-8(%rbp), %rax
	movl	12(%rax), %r9d
	movq	-8(%rbp), %rax
	movl	16(%rax), %eax
	leal	1(%rax), %r10d
	movq	-8(%rbp), %rax
	movl	20(%rax), %eax
	addl	$1900, %eax
	movl	%r8d, 48(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, 32(%rsp)
	movl	%r10d, %r8d
	movl	%eax, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	nop
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	addTwoNumbers
	.def	addTwoNumbers;	.scl	2;	.type	32;	.endef
	.seh_proc	addTwoNumbers
addTwoNumbers:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC2:
	.ascii "result: %d\12\0"
.LC3:
	.ascii "%d %d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	greet
	call	displayCurrentDate
	movl	$20, %edx
	movl	$10, %ecx
	call	addTwoNumbers
	movl	%eax, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$30, %r9d
	movl	$20, %r8d
	movl	$10, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 12.4.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	time;	.scl	2;	.type	32;	.endef
	.def	localtime;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
