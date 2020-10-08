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
bgtz $s0, 3 
sw $t1, 0($a0)
sw $t0, 4($a0) 
sub $s0, $t2, $t1
bgtz $s0, 3 
sw $t2, 4($a0) 
sw $t1, 8($a0) 
sub $s0, $t3, $t2
bgtz $s0, 3 
sw $t3, 8($a0)
sw $t2, c($a0)
sub $s0, $t4, $t3
bgtz $s0, 3 
sw $t4, c($a0)
sw $t3, 10($a0)
sub $s0, $t5, $t4
bgtz $s0, 3 
sw $t5, 10($a0)
sw $t4, 14($a0)
sub $s0, $t6, $t5
bgtz $s0, 3 
sw $t6, 14($a0)
sw $t5, 18($a0)
sub $s0, $t7, $t6
bgtz $s0, 3 
sw $t7, 18($a0)
sw $t6, 1c($a0)
sub $s0, $t8, $t7
bgtz $s0, 3 
sw $t8, 1c($a0)
sw $t7, 20($a0)
sub $s0, $t9, $t8
bgtz $s0, 3 
sw $t9, 20($a0)
sw $t8, 24($a0)
addiu $v0, $zero, 0xa
syscall
