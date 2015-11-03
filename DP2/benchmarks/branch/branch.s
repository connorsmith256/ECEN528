.align 2
.globl main
main:
    ; r2 iterator
    ; r3 branch1
    ; r4 branch2
    ; r5 branch3
    ; r6 compare

    add r2, r0, r0
    add r3, r0, r0
    add r4, r0, r0
    add r5, r0, r0

TOP:
BRANCH1:
    beqz r3, BRANCH2
    nop
BRANCH2:
    beqz r4, BRANCH3
    nop
BRANCH3:
    beqz r5, BOTTOM        ; The branch to test.
    nop
BOTTOM:
    addi r2, r2, #1
    andi r3, r2, #1
    andi r4, r2, #2
    andi r5, r2, #8
    andi r6, r2, #32
    beqz r6, TOP
    nop

    trap #0
    nop
	.end main

