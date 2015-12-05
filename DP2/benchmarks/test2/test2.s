;; 	DLX assembly file generated by lcc 
.align 2
exit: 
	trap #0
	nop
	jr r31
	nop
	.end exit
fopen: 
	trap #1
	nop
	jr r31
	nop
	.end fopen
fclose: 
	trap #2
	nop
	jr r31
	nop
	.end fclose
fread: 
	trap #3
	nop
	jr r31
	nop
	.end fread
fwrite: 
	trap #4
	nop
	jr r31
	nop
	.end fwrite
printf: 
	trap #5
	nop
	jr r31
	nop
	.end printf
scanf: 
	trap #6
	nop
	jr r31
	nop
	.end scanf
fprintf: 
	trap #7
	nop
	jr r31
	nop
	.end fprintf
fscanf: 
	trap #8
	nop
	jr r31
	nop
	.end fscanf
feof: 
	trap #9
	nop
	jr r31
	nop
	.end feof
malloc: 
	trap #10
	nop
	jr r31
	nop
	.end malloc
sprintf: 
	trap #11
	nop
	jr r31
	nop
	.end sprintf
.data
.globl i2
.align 2
.comm i2,4
.globl i1
.align 2
.comm i1,4
.align 3
d2:	
	.word 0x3fe80000
	.word 0x0
.align 3
d1:	
	.word 0x40120000
	.word 0x0
.globl main
.text
.text
.align 2
main:
	;; set up offsets for variable accesses
	addui r2,r0,#196
	addui r3,r0,#200
	addui r4,r0,#208
	addui r1,r0,#192
	lw r5,0(r1)		; NS:	int --> load
	lw r6,0(r5)		;  1:	RAW load --> load
	add r8,r6,r7		;  1:	RAW load --> int
	movi2fp f0,r8		; NS:	RAW int --> int
	cvti2d f2,f0		; NS:	RAW int --> add
	sd 0(r3),f2		; NS:	RAW add --> store
	ld f18,0(r3)
	sd 0(r3),f18		; NS:	RAW load --> store
	add r8,r2,r3
	sw 0(r1),r8		; NS:	RAW int --> store
	cvtd2i f4,f18
	movfp2i r9,f4		;  1:	RAW add --> int
	ld f16,0(r3)
	multd f12,f12,f16	;  1:	RAW load --> mult
	sd 0(r3),f12		;  3:	RAW mult --> store
	ld f24,0(r4)
	addd f6,f24,f14		;  1:	RAW load --> add
	cvtd2i f4,f6		;  1:	RAW add --> add
	movfp2i r8,f4		;  1:	RAW add --> int
	ld f24,0(r3)
	divd f6,f24,f18		;  1:	RAW load --> div
	sd 0(r3),f6		; 17:	RAW div --> store
	divd f6,f28,f18
	multd f10,f20,f6	; 18:	RAW div --> mult
	addd f2,f10,f20		;  4:	RAW mult --> add
	multd f4,f10,f20
	divd f2,f4,f18		;  4:	RAW mult --> div
	addd f2,f4,f2		; 20:	WAW div --> add
	divd f8,f2,f18		;  1:	RAW add --> div
	divd f10,f8,f18		; 18:	RAW div --> div
	addd f10,f6,f12		; 20:	WAW div --> add
	gtd f6,f8
	bfpt L1			;  1:	WAW add --> fps
	nop
	jal exit
	nop
L1:	jal exit
	nop
	.end main
