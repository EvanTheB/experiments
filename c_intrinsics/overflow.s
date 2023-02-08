	.file	"overflow.c"
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 9.2.1-8) 9.2.1 20190909"
	.section	.note.GNU-stack,"",@progbits
