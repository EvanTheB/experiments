	.file	"mul_type.c"
# GNU C17 (Debian 9.2.1-8) version 9.2.1 20190909 (x86_64-linux-gnu)
#	compiled by GNU C version 9.2.1 20190909, GMP version 6.1.2, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.21-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu mul_type.c -mtune=generic
# -march=x86-64 -fverbose-asm -fasynchronous-unwind-tables
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
# -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
# -fipa-stack-alignment -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fshrink-wrap-separate
# -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
.LC0:
	.string	"%u\n"
.LC1:
	.string	"%llu\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$48, %rsp	#,
	movl	%edi, -36(%rbp)	# argc, argc
	movq	%rsi, -48(%rbp)	# argv, argv
# mul_type.c:10:     a = UINT32_MAX - 1;
	movl	$-2, -4(%rbp)	#, a
# mul_type.c:11:     b = 2;
	movl	$2, -8(%rbp)	#, b
# mul_type.c:13:     printf("%u\n", a);
	movl	-4(%rbp), %eax	# a, tmp89
	movl	%eax, %esi	# tmp89,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# mul_type.c:14:     printf("%u\n", a*b);
	movl	-4(%rbp), %eax	# a, tmp90
	imull	-8(%rbp), %eax	# b, _1
	movl	%eax, %esi	# _1,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# mul_type.c:15:     printf("%llu\n", a*b);
	movl	-4(%rbp), %eax	# a, tmp91
	imull	-8(%rbp), %eax	# b, _2
	movl	%eax, %esi	# _2,
	leaq	.LC1(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# mul_type.c:17:     r = a * b;
	movl	-4(%rbp), %eax	# a, tmp93
	imull	-8(%rbp), %eax	# b, tmp92
	movl	%eax, -12(%rbp)	# tmp92, r
# mul_type.c:18:     printf("%u\n", r);
	movl	-12(%rbp), %eax	# r, tmp94
	movl	%eax, %esi	# tmp94,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# mul_type.c:20:     r2 = a * b;
	movl	-4(%rbp), %eax	# a, tmp95
	imull	-8(%rbp), %eax	# b, _3
# mul_type.c:20:     r2 = a * b;
	movl	%eax, %eax	# _3, tmp100
	movq	%rax, -24(%rbp)	# tmp100, r2
# mul_type.c:21:     printf("%llu\n", r2);
	movq	-24(%rbp), %rax	# r2, tmp96
	movq	%rax, %rsi	# tmp96,
	leaq	.LC1(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# mul_type.c:23:     r2 = (unsigned long long)a * b;
	movl	-4(%rbp), %edx	# a, _4
# mul_type.c:23:     r2 = (unsigned long long)a * b;
	movl	-8(%rbp), %eax	# b, _5
# mul_type.c:23:     r2 = (unsigned long long)a * b;
	imulq	%rdx, %rax	# _4, tmp97
	movq	%rax, -24(%rbp)	# tmp97, r2
# mul_type.c:24:     printf("%llu\n", r2);
	movq	-24(%rbp), %rax	# r2, tmp98
	movq	%rax, %rsi	# tmp98,
	leaq	.LC1(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# mul_type.c:26:     return 0;
	movl	$0, %eax	#, _18
# mul_type.c:27: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 9.2.1-8) 9.2.1 20190909"
	.section	.note.GNU-stack,"",@progbits
