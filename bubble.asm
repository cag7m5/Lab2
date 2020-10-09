lui $a0, 0x1001 
addiu $t0, $zero, 5 
addiu $t1, $zero, 3 
addiu $t2, $zero, 6
addiu $t3, $zero, 8 
addiu $t4, $zero, 9
addiu $t5, $zero, 1 
addiu $t6, $zero, 4
addiu $t7, $zero, 7 
addiu $t8, $zero, 2
addiu $t9, $zero, a 
sw $t0, 0($a0)
sw $t1, 4($a0) 
sw $t2, 8($a0)
sw $t3, c($a0)  
sw $t4, 10($a0)
sw $t5, 14($a0) 
sw $t6, 18($a0)
sw $t7, 1c($a0)
sw $t8, 20($a0)
sw $t9, 24($a0) 
sub $s0, $t1, $t0 
bltz $s0, 2
bgtz $s0, 8
sw $t1, 0($a0)
sw $t0, 4($a0)
addiu $a1, $t0, 0
addiu $a2, $t1, 0
addiu $t0, $a2, 0
addiu $t1, $a1, 0
jal 0x100015
sub $s0, $t2, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t2, 0($a0)
sw $t0, 8($a0)
addiu $a1, $t0, 0
addiu $a2, $t2, 0
addiu $t0, $a2, 0
addiu $t2, $a1, 0
jal 0x100015
sub $s0, $t3, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t3, 0($a0)
sw $t0, c($a0)
addiu $a1, $t0, 0
addiu $a2, $t3, 0
addiu $t0, $a2, 0
addiu $t3, $a1, 0
jal 0x100015
sub $s0, $t4, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t4, 0($a0)
sw $t0, 10($a0)
addiu $a1, $t0, 0
addiu $a2, $t4, 0
addiu $t0, $a2, 0
addiu $t4, $a1, 0
jal 0x100015
sub $s0, $t5, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t5, 0($a0)
sw $t0, 14($a0)
addiu $a1, $t0, 0
addiu $a2, $t5, 0
addiu $t0, $a2, 0
addiu $t5, $a1, 0
jal 0x100015
sub $s0, $t6, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t6, 0($a0)
sw $t0, 18($a0)
addiu $a1, $t0, 0
addiu $a2, $t6, 0
addiu $t0, $a2, 0
addiu $t6, $a1, 0
jal 0x100015
sub $s0, $t7, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t7, 0($a0)
sw $t0, 1c($a0)
addiu $a1, $t0, 0
addiu $a2, $t7, 0
addiu $t0, $a2, 0
addiu $t7, $a1, 0
jal 0x100015
sub $s0, $t8, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t8, 0($a0)
sw $t0, 20($a0)
addiu $a1, $t0, 0
addiu $a2, $t8, 0
addiu $t0, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t0
bltz $s0, 2
bgtz $s0, 8
sw $t9, 0($a0)
sw $t0, 24($a0)
addiu $a1, $t0, 0
addiu $a2, $t9, 0
addiu $t0, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t2, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t2, 4($a0) 
sw $t1, 8($a0)
addiu $a1, $t1, 0
addiu $a2, $t2, 0
addiu $t1, $a2, 0
addiu $t2, $a1, 0
jal 0x100015
sub $s0, $t3, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t3, 4($a0) 
sw $t1, c($a0)
addiu $a1, $t1, 0
addiu $a2, $t3, 0
addiu $t1, $a2, 0
addiu $t3, $a1, 0
jal 0x100015
sub $s0, $t4, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t4, 4($a0) 
sw $t1, 10($a0) 
addiu $a1, $t1, 0
addiu $a2, $t4, 0
addiu $t1, $a2, 0
addiu $t4, $a1, 0
jal 0x100015
sub $s0, $t5, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t5, 4($a0) 
sw $t1, 14($a0) 
addiu $a1, $t1, 0
addiu $a2, $t5, 0
addiu $t1, $a2, 0
addiu $t5, $a1, 0
jal 0x100015
sub $s0, $t6, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t6, 4($a0) 
sw $t1, 18($a0) 
addiu $a1, $t1, 0
addiu $a2, $t6, 0
addiu $t1, $a2, 0
addiu $t6, $a1, 0
jal 0x100015
sub $s0, $t7, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t7, 4($a0) 
sw $t1, 1c($a0)
addiu $a1, $t1, 0
addiu $a2, $t7, 0
addiu $t1, $a2, 0
addiu $t7, $a1, 0
jal 0x100015
sub $s0, $t8, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t8, 4($a0) 
sw $t1, 20($a0)
addiu $a1, $t1, 0
addiu $a2, $t8, 0
addiu $t1, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t1
bltz $s0, 2
bgtz $s0, 8
sw $t9, 4($a0) 
sw $t1, 24($a0) 
addiu $a1, $t1, 0
addiu $a2, $t9, 0
addiu $t1, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t3, $t2
bltz $s0, 2
bgtz $s0, 8
sw $t3, 8($a0)
sw $t2, c($a0)
addiu $a1, $t2, 0
addiu $a2, $t3, 0
addiu $t2, $a2, 0
addiu $t3, $a1, 0
jal 0x100015
sub $s0, $t4, $t2
bltz $s0, 2
bgtz $s0, 8
sw $t4, 8($a0)
sw $t2, 10($a0)
addiu $a1, $t2, 0
addiu $a2, $t4, 0
addiu $t2, $a2, 0
addiu $t4, $a1, 0
jal 0x100015
sub $s0, $t5, $t2
bltz $s0, 2
bgtz $s0, 8
sw $t5, 8($a0)
sw $t2, 14($a0)
addiu $a1, $t2, 0
addiu $a2, $t5, 0
addiu $t2, $a2, 0
addiu $t5, $a1, 0
jal 0x100015
sub $s0, $t6, $t2
bltz $s0, 2
bgtz $s0, 8
sw $t6, 8($a0)
sw $t2, 18($a0)
addiu $a1, $t2, 0
addiu $a2, $t6, 0
addiu $t2, $a2, 0
addiu $t6, $a1, 0
jal 0x100015
sub $s0, $t7, $t2
bltz $s0, 2
bgtz $s0, 8
sw $t7, 8($a0)
sw $t2, 1c($a0)
addiu $a1, $t2, 0
addiu $a2, $t7, 0
addiu $t2, $a2, 0
addiu $t7, $a1, 0
jal 0x100015
sub $s0, $t8, $t2
bltz $s0, 2
bgtz $s0, 8
sw $t8, 8($a0)
sw $t2, 20($a0)
addiu $a1, $t2, 0
addiu $a2, $t8, 0
addiu $t2, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t2
bltz $s0, 2
bgtz $s0, 8
sw $t9, 8($a0)
sw $t2, 24($a0)
addiu $a1, $t2, 0
addiu $a2, $t9, 0
addiu $t2, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t4, $t3
bltz $s0, 2
bgtz $s0, 8
sw $t4, c($a0)
sw $t3, 10($a0)
addiu $a1, $t3, 0
addiu $a2, $t4, 0
addiu $t3, $a2, 0
addiu $t4, $a1, 0
jal 0x100015
sub $s0, $t5, $t3
bltz $s0, 2
bgtz $s0, 8
sw $t5, c($a0)
sw $t3, 14($a0)
addiu $a1, $t3, 0
addiu $a2, $t5, 0
addiu $t3, $a2, 0
addiu $t5, $a1, 0
jal 0x100015
sub $s0, $t6, $t3
bltz $s0, 2
bgtz $s0, 8
sw $t6, c($a0)
sw $t3, 18($a0)
addiu $a1, $t3, 0
addiu $a2, $t6, 0
addiu $t3, $a2, 0
addiu $t6, $a1, 0
jal 0x100015
sub $s0, $t7, $t3
bltz $s0, 2
bgtz $s0, 8
sw $t7, c($a0)
sw $t3, 1c($a0)
addiu $a1, $t3, 0
addiu $a2, $t7, 0
addiu $t3, $a2, 0
addiu $t7, $a1, 0
jal 0x100015
sub $s0, $t8, $t3
bltz $s0, 2
bgtz $s0, 8
sw $t8, c($a0)
sw $t3, 20($a0)
addiu $a1, $t3, 0
addiu $a2, $t8, 0
addiu $t3, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t3
bltz $s0, 2
bgtz $s0, 8
sw $t4, c($a0)
sw $t3, 24($a0)
addiu $a1, $t3, 0
addiu $a2, $t9, 0
addiu $t3, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t5, $t4
bltz $s0, 2
bgtz $s0, 8
sw $t5, 10($a0)
sw $t4, 14($a0)
addiu $a1, $t4, 0
addiu $a2, $t5, 0
addiu $t4, $a2, 0
addiu $t5, $a1, 0
jal 0x100015
sub $s0, $t6, $t4
bltz $s0, 2
bgtz $s0, 8
sw $t6, 10($a0)
sw $t4, 18($a0)
addiu $a1, $t4, 0
addiu $a2, $t6, 0
addiu $t4, $a2, 0
addiu $t6, $a1, 0
jal 0x100015
sub $s0, $t7, $t4
bltz $s0, 2
bgtz $s0, 8
sw $t7, 10($a0)
sw $t4, 1c($a0)
addiu $a1, $t4, 0
addiu $a2, $t7, 0
addiu $t4, $a2, 0
addiu $t7, $a1, 0
jal 0x100015
sub $s0, $t8, $t4
bltz $s0, 2
bgtz $s0, 8
sw $t8, 10($a0)
sw $t4, 20($a0)
addiu $a1, $t4, 0
addiu $a2, $t8, 0
addiu $t4, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t4
bltz $s0, 2
bgtz $s0, 8
sw $t9, 10($a0)
sw $t4, 24($a0)
addiu $a1, $t4, 0
addiu $a2, $t9, 0
addiu $t4, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t6, $t5
bltz $s0, 2
bgtz $s0, 8
sw $t6, 14($a0)
sw $t5, 18($a0)
addiu $a1, $t5, 0
addiu $a2, $t6, 0
addiu $t5, $a2, 0
addiu $t6, $a1, 0
jal 0x100015
sub $s0, $t7, $t5
bltz $s0, 2
bgtz $s0, 8
sw $t7, 14($a0)
sw $t5, 1c($a0)
addiu $a1, $t5, 0
addiu $a2, $t7, 0
addiu $t5, $a2, 0
addiu $t7, $a1, 0
jal 0x100015
sub $s0, $t8, $t5
bltz $s0, 2
bgtz $s0, 8
sw $t8, 14($a0)
sw $t5, 20($a0)
addiu $a1, $t5, 0
addiu $a2, $t8, 0
addiu $t5, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t5
bltz $s0, 2
bgtz $s0, 8
sw $t9, 14($a0)
sw $t5, 24($a0)
addiu $a1, $t5, 0
addiu $a2, $t9, 0
addiu $t5, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t7, $t6
bltz $s0, 2
bgtz $s0, 8
sw $t7, 18($a0)
sw $t6, 1c($a0)
addiu $a1, $t6, 0
addiu $a2, $t7, 0
addiu $t6, $a2, 0
addiu $t7, $a1, 0
jal 0x100015
sub $s0, $t8, $t6
bltz $s0, 2
bgtz $s0, 8
sw $t8, 18($a0)
sw $t6, 20($a0)
addiu $a1, $t6, 0
addiu $a2, $t8, 0
addiu $t6, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t6
bltz $s0, 2
bgtz $s0, 8
sw $t9, 18($a0)
sw $t6, 24($a0)
addiu $a1, $t6, 0
addiu $a2, $t9, 0
addiu $t6, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t8, $t7
bltz $s0, 2
bgtz $s0, 8
sw $t8, 1c($a0)
sw $t7, 20($a0)
addiu $a1, $t7, 0
addiu $a2, $t8, 0
addiu $t7, $a2, 0
addiu $t8, $a1, 0
jal 0x100015
sub $s0, $t9, $t7
bltz $s0, 2
bgtz $s0, 8
sw $t9, 1c($a0)
sw $t7, 24($a0)
addiu $a1, $t7, 0
addiu $a2, $t9, 0
addiu $t7, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
sub $s0, $t9, $t8
bltz $s0, 2
bgtz $s0, 8
sw $t9, 20($a0)
sw $t8, 24($a0)
addiu $a1, $t8, 0
addiu $a2, $t9, 0
addiu $t8, $a2, 0
addiu $t9, $a1, 0
jal 0x100015
addiu $v0, $zero, 0xa
syscall
