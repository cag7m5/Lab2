lui $gp, 1001
addiu $t0, $t0, 0x0
addiu $s0, $t0, 0x0
sw $s0, 0($gp)
addiu $t1, $t1, 0x1
addiu $s1, $t1, 0x0
sw $s1, 4($gp)
add $t2, $t0, $t1
addiu $s2, $t2, 0x0
sw $s2, 8($gp)
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
addiu $s3, $t2, 0x0
sw $s3, c($gp)
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
addiu $s4, $t2, 0x0
sw $s4, 10($gp)
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
addiu $s5, $t2, 0x0
sw $s5, 14($gp)
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
addiu $s6, $t2, 0x0
sw $s6, 18($gp)
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
addiu $s7, $t2, 0x0
sw $s7, 1c($gp)
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
addiu $t8, $t2, 0x0
sw $t8, 20($gp)
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
addiu $t9, $t2, 0x0
sw $t9, 24($gp)
addiu $v0, $zero, 0xa
syscall
