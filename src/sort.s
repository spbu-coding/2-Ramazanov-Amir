	.file	"sort.c"
	.text
	.p2align 4
	.globl	sort
	.type	sort, @function
sort:
.LFB0:
	.cfi_startproc
	endbr64
	testl	%esi, %esi
	jle	.L1
	leal	-2(%rsi), %eax
	leal	1(%rsi), %r10d
	movl	$1, %r9d
	leaq	4(%rdi,%rax,4), %r8
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%rdi, %rax
	cmpl	$1, %esi
	je	.L6
	.p2align 4,,10
	.p2align 3
.L5:
	movl	(%rax), %ecx
	movl	4(%rax), %edx
	cmpl	%edx, %ecx
	jl	.L4
	movl	%ecx, 4(%rax)
	movl	%edx, (%rax)
.L4:
	addq	$4, %rax
	cmpq	%r8, %rax
	jne	.L5
.L6:
	addl	$1, %r9d
	cmpl	%r10d, %r9d
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	sort, .-sort
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
