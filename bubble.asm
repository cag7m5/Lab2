#Data segment base address is 0x1001000
addiu $a0, $zero, 0x1001
sll $a0, $a0, 16    
addiu $a0, $a0, 0x0000  

#Store values in temporary registers;
addiu $t0, $zero, 5 
addiu $t1, $zero, 3 #0x10
addiu $t2, $zero, 6
addiu $t3, $zero, 8
addiu $t4, $zero, 9
addiu $t5, $zero, 1 #0x20
addiu $t6, $zero, 4
addiu $t7, $zero, 7
addiu $t8, $zero, 2
addiu $t9, $zero, a #0x30

#Store values from registers into memory of a0 (makes array)
sw $t0, 0($a0)
sw $t1, 4($a0)
sw $t2, 8($a0)
sw $t3, c($a0)  #0x40
sw $t4, 10($a0)
sw $t5, 14($a0)
sw $t6, 18($a0)
sw $t7, 1c($a0) #0x50
sw $t8, 20($a0)
sw $t9, 24($a0)

#Sort
sub $s0, $t0, $t1
bgtz $s0, 64  #0x60 branch to 64 if t0 > t1
sub $s0, $t1, $t2
bgtz $s0, 6c #branch to 6c if t1 > t2
sub $s0, $t2, $t3
bgtz $s0, 74 #0x70 branch to 74 if t2 > t3
sub $s0, $t3, $t4
bgtz $s0, 7c #branch to 7c if t3 > t4
sub $s0, $t4, $t5
bgtz $s0, 84 #0x80 branch to 84 if t4 > t5
sub $s0, $t5, $t6
bgtz $s0, 8c #branch to 8c if t5 > t6
sub $s0, $t6, $t7
bgtz $s0, 94 #0x90 branch to 94 if t6 > t7
sub $s0, $t7, $t8
bgtz $s0, 9c #branch to 9c if t7 > t8
sub $s0, $t8, $t9
bgtz $s0, 104 #0x100 branch to 104 if t8 > t9




