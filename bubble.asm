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
addiu $t9, $zero, A #0x30

#Store values from registers into memory of a0 (makes array)
sw $t0, 0($a0)
sw $t1, 4($a0)
sw $t2, 8($a0)
sw $t3, C($a0)  #0x40
sw $t4, 10($a0)
sw $t5, 14($a0)
sw $t6, 18($a0)
sw $t7, 1C($a0) #0x50
sw $t8, 20($a0)
sw $t9, 24($a0)

#Compare values in registers
sub $s0, $t1, $t0 #If t0 > t1
bltz $s0, ??    #0x60
