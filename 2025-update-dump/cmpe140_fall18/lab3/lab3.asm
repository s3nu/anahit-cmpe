########################
# Variable declaration #
########################
# $a0 = a
# $a1 = b
# $s0 = c
# $s1 = x
# $s2 = y

#################
# Begin Program #
#################
var_init:   
	addiu $a0, $0, 0x8000  # a = 0x8000
        addiu $a1, $0, 0x00A9  # b = 0x00A9
        addi $s0, $0, 1974	# c = 1974 
arit_comp:
        multu $a0, $a0		# x = a * a
        mflo $s1		
        sw $s1, 0x20		# store x in address 20
        multu $s1, $a1		# y = x * b
        mflo $s2		
        sw $s2, 0x24		# store y in address 24
        srl $s2, $s2, 16	# y = y >> 2
        divu $s2, $s0          # y/c
        mflo $t0
        addu $t0, $t0, $s0     # c + y/c
        srl $s0, $t0, 1		# c = (c + y/c)/2
        sw $s0, 0x2c		# store c in address 2c
while_loop:
	ble $s0, 1665, end_loop
	divu $s2, $s0		# y/c
	mflo $t0
	addu $t0, $t0, $s0	# c + y/c
	srl $s0, $t0, 1		# c = (c + y/c)/2
	j while_loop
end_loop:
	sll $s0, $s0, 8		# c = c << 8
	sw $s0, 0x30
	
        
        
        
        