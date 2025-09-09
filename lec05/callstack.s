	.file	"callstack.cpp"
# GNU C++17 (GCC) version 15.2.1 20250813 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 15.2.1 20250813, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.3.1, isl version isl-0.27-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.globl	_Z5func1v
	.type	_Z5func1v, @function
_Z5func1v:
.LFB1984:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# callstack.cpp:7:     long long x = 23232323;
	movq	$23232323, -16(%rbp)	#, x
# callstack.cpp:8:     long long y = 11001100;
	movq	$11001100, -8(%rbp)	#, y
# callstack.cpp:9:     func2();
	call	_Z5func2v	#
# callstack.cpp:10: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1984:
	.size	_Z5func1v, .-_Z5func1v
	.section	.rodata
.LC0:
	.string	"Address of main: "
.LC1:
	.string	"Address of func1: "
	.text
	.globl	_Z5func2v
	.type	_Z5func2v, @function
_Z5func2v:
.LFB1985:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# callstack.cpp:12: void func2() {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp109
	movq	%rax, -8(%rbp)	# tmp109, D.53443
	xorl	%eax, %eax	# tmp109
# callstack.cpp:13:     long long z = 87654321;
	movq	$87654321, -24(%rbp)	#, z
# callstack.cpp:15:     long long *p = &z;
	leaq	-24(%rbp), %rax	#, tmp110
	movq	%rax, -16(%rbp)	# tmp110, p
# callstack.cpp:17:     std::cout << "Address of main: " << (long long) main << std::endl;
	leaq	.LC0(%rip), %rdx	#, tmp111
	leaq	_ZSt4cout(%rip), %rax	#, tmp112
	movq	%rdx, %rsi	# tmp111,
	movq	%rax, %rdi	# tmp112,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	#, _1
# callstack.cpp:17:     std::cout << "Address of main: " << (long long) main << std::endl;
	leaq	main(%rip), %rax	#, main.0_2
	movq	%rax, %rsi	# main.0_2,
	movq	%rdx, %rdi	# _1,
	call	_ZNSolsEx@PLT	#
# callstack.cpp:17:     std::cout << "Address of main: " << (long long) main << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx	#, tmp114
	movq	%rdx, %rsi	# tmp113,
	movq	%rax, %rdi	# _3,
	call	_ZNSolsEPFRSoS_E@PLT	#
# callstack.cpp:18:     std::cout << "Address of func1: " << (long long) func1 << std::endl;
	leaq	.LC1(%rip), %rdx	#, tmp115
	leaq	_ZSt4cout(%rip), %rax	#, tmp116
	movq	%rdx, %rsi	# tmp115,
	movq	%rax, %rdi	# tmp116,
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT	#
	movq	%rax, %rdx	#, _4
# callstack.cpp:18:     std::cout << "Address of func1: " << (long long) func1 << std::endl;
	leaq	_Z5func1v(%rip), %rax	#, func1.1_5
	movq	%rax, %rsi	# func1.1_5,
	movq	%rdx, %rdi	# _4,
	call	_ZNSolsEx@PLT	#
# callstack.cpp:18:     std::cout << "Address of func1: " << (long long) func1 << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx	#, tmp118
	movq	%rdx, %rsi	# tmp117,
	movq	%rax, %rdi	# _6,
	call	_ZNSolsEPFRSoS_E@PLT	#
# callstack.cpp:19:     for (int i = 0; i < 11; i++) {
	movl	$0, -28(%rbp)	#, i
# callstack.cpp:19:     for (int i = 0; i < 11; i++) {
	jmp	.L3	#
.L4:
# callstack.cpp:20:         std::cout << p[i] << std::endl;
	movl	-28(%rbp), %eax	# i, tmp119
	cltq
# callstack.cpp:20:         std::cout << p[i] << std::endl;
	leaq	0(,%rax,8), %rdx	#, _8
	movq	-16(%rbp), %rax	# p, tmp120
	addq	%rdx, %rax	# _8, _9
	movq	(%rax), %rax	# *_9, _10
	leaq	_ZSt4cout(%rip), %rdx	#, tmp121
	movq	%rax, %rsi	# _10,
	movq	%rdx, %rdi	# tmp121,
	call	_ZNSolsEx@PLT	#
# callstack.cpp:20:         std::cout << p[i] << std::endl;
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx	#, tmp123
	movq	%rdx, %rsi	# tmp122,
	movq	%rax, %rdi	# _11,
	call	_ZNSolsEPFRSoS_E@PLT	#
# callstack.cpp:19:     for (int i = 0; i < 11; i++) {
	addl	$1, -28(%rbp)	#, i
.L3:
# callstack.cpp:19:     for (int i = 0; i < 11; i++) {
	cmpl	$10, -28(%rbp)	#, i
	jle	.L4	#,
# callstack.cpp:22: }
	nop	
	movq	-8(%rbp), %rax	# D.53443, tmp124
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp124
	je	.L5	#,
	call	__stack_chk_fail@PLT	#
.L5:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1985:
	.size	_Z5func2v, .-_Z5func2v
	.globl	main
	.type	main, @function
main:
.LFB1986:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# callstack.cpp:25:     long long w = 12345678;
	movq	$12345678, -8(%rbp)	#, w
# callstack.cpp:26:     func1();
	call	_Z5func1v	#
# callstack.cpp:27: }
	movl	$0, %eax	#, _4
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1986:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
