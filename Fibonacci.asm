addiu $t0, $t0, 0x0
addiu $t1, $t1, 0x1
add $t2, $t0, $t1
addiu $t0, $t1, 0x0
addiu $t1, $t2, 0x0
add $t2, $t0, $t1
syscall
