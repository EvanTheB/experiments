	.file	"melt.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%u"
.LC1:
	.string	"%u\n"
.LC2:
	.string	"r"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB42:
	.cfi_startproc
	leaq	8(%rsp), %r10
	.cfi_def_cfa 10, 0
	andq	$-32, %rsp
	pushq	-8(%r10)
	pushq	%rbp
	.cfi_escape 0x10,0x6,0x2,0x76,0
	movq	%rsp, %rbp
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%r10
	.cfi_escape 0xf,0x3,0x76,0x60,0x6
	.cfi_escape 0x10,0xe,0x2,0x76,0x78
	.cfi_escape 0x10,0xd,0x2,0x76,0x70
	.cfi_escape 0x10,0xc,0x2,0x76,0x68
	movq	%rsi, %r14
	pushq	%rbx
	leaq	-60(%rbp), %rdx
	subq	$40, %rsp
	.cfi_escape 0x10,0x3,0x2,0x76,0x58
	movq	8(%rsi), %rdi
	leaq	.LC0(%rip), %rsi
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	call	__isoc99_sscanf@PLT
	movl	-60(%rbp), %edx
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movl	-60(%rbp), %r12d
	movl	$32, %esi
	salq	$2, %r12
	movq	%r12, %rdi
	call	aligned_alloc@PLT
	movq	%r12, %rdi
	movl	$32, %esi
	movq	%rax, %rbx
	call	aligned_alloc@PLT
	movq	%r12, %rdi
	movl	$32, %esi
	movq	%rax, %r13
	call	aligned_alloc@PLT
	movq	16(%r14), %rdi
	leaq	.LC2(%rip), %rsi
	movq	%rax, %r12
	call	fopen@PLT
	movl	-60(%rbp), %ecx
	movq	%rax, %r8
	movl	$4, %edx
	movl	$32, %esi
	movq	%rbx, %rdi
	movq	%rax, %r14
	call	__fread_chk@PLT
	movl	-60(%rbp), %ecx
	movq	%r13, %rdi
	movq	%r14, %r8
	movl	$4, %edx
	movl	$32, %esi
	call	__fread_chk@PLT
	movl	-60(%rbp), %edi
	testq	%rdi, %rdi
	je	.L2
	movq	%rbx, %rdx
	leaq	-1(%rdi), %rcx
	shrq	$2, %rdx
	negq	%rdx
	andl	$7, %edx
	leaq	7(%rdx), %rax
	cmpq	%rax, %rcx
	jb	.L9
	testq	%rdx, %rdx
	je	.L10
	movl	0(%r13), %eax
	addl	(%rbx), %eax
	cmpq	$1, %rdx
	movl	%eax, (%r12)
	je	.L11
	movl	4(%r13), %eax
	addl	4(%rbx), %eax
	cmpq	$2, %rdx
	movl	%eax, 4(%r12)
	je	.L12
	movl	8(%r13), %eax
	addl	8(%rbx), %eax
	cmpq	$3, %rdx
	movl	%eax, 8(%r12)
	je	.L13
	movl	12(%r13), %eax
	addl	12(%rbx), %eax
	cmpq	$4, %rdx
	movl	%eax, 12(%r12)
	je	.L14
	movl	16(%r13), %eax
	addl	16(%rbx), %eax
	cmpq	$5, %rdx
	movl	%eax, 16(%r12)
	je	.L15
	movl	20(%r13), %eax
	addl	20(%rbx), %eax
	cmpq	$7, %rdx
	movl	%eax, 20(%r12)
	jne	.L16
	movl	24(%rbx), %eax
	addl	24(%r13), %eax
	movl	$7, %r11d
	movl	%eax, 24(%r12)
.L4:
	movq	%rdi, %r10
	xorl	%eax, %eax
	xorl	%ecx, %ecx
	subq	%rdx, %r10
	salq	$2, %rdx
	movq	%r10, %r9
	leaq	(%rbx,%rdx), %r8
	leaq	0(%r13,%rdx), %rsi
	shrq	$3, %r9
	addq	%r12, %rdx
	.p2align 4,,10
	.p2align 3
.L6:
	vmovdqu	(%rsi,%rax), %xmm0
	addq	$1, %rcx
	vinserti128	$0x1, 16(%rsi,%rax), %ymm0, %ymm0
	vpaddd	(%r8,%rax), %ymm0, %ymm0
	vmovups	%xmm0, (%rdx,%rax)
	vextracti128	$0x1, %ymm0, 16(%rdx,%rax)
	addq	$32, %rax
	cmpq	%r9, %rcx
	jb	.L6
	movq	%r10, %rdx
	andq	$-8, %rdx
	cmpq	%rdx, %r10
	leaq	(%r11,%rdx), %rax
	je	.L25
	vzeroupper
.L3:
	movl	0(%r13,%rax,4), %edx
	addl	(%rbx,%rax,4), %edx
	movl	%edx, (%r12,%rax,4)
	leaq	1(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	2(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	3(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	4(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	5(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	6(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	7(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	8(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	9(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	10(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	11(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	movl	%ecx, (%r12,%rdx,4)
	leaq	12(%rax), %rdx
	cmpq	%rdx, %rdi
	jbe	.L2
	movl	0(%r13,%rdx,4), %ecx
	addl	(%rbx,%rdx,4), %ecx
	addq	$13, %rax
	cmpq	%rax, %rdi
	movl	%ecx, (%r12,%rdx,4)
	jbe	.L2
	movl	0(%r13,%rax,4), %edx
	addl	(%rbx,%rax,4), %edx
	movl	%edx, (%r12,%rax,4)
	.p2align 4,,10
	.p2align 3
.L2:
	movl	(%r12), %edx
	leaq	.LC1(%rip), %rsi
	xorl	%eax, %eax
	movl	$1, %edi
	call	__printf_chk@PLT
	xorl	%eax, %eax
	movq	-56(%rbp), %rbx
	xorq	%fs:40, %rbx
	jne	.L26
	addq	$40, %rsp
	popq	%rbx
	popq	%r10
	.cfi_remember_state
	.cfi_def_cfa 10, 0
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%rbp
	leaq	-8(%r10), %rsp
	.cfi_def_cfa 7, 8
	ret
.L12:
	.cfi_restore_state
	movl	$2, %r11d
	jmp	.L4
.L11:
	movl	$1, %r11d
	jmp	.L4
.L25:
	vzeroupper
	jmp	.L2
.L10:
	xorl	%r11d, %r11d
	jmp	.L4
.L9:
	xorl	%eax, %eax
	jmp	.L3
.L13:
	movl	$3, %r11d
	jmp	.L4
.L14:
	movl	$4, %r11d
	jmp	.L4
.L15:
	movl	$5, %r11d
	jmp	.L4
.L16:
	movl	$6, %r11d
	jmp	.L4
.L26:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE42:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-16ubuntu3) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
