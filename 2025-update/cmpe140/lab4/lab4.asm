# $a0 = array base address
# $a1 = n
# $s0 = n!
Main:
	li $a0, 0x100	#array base address = 0x100
	li $a1, 0	#i = 0
	li $t0, 3	
	li $t1, 50	# $t1 = 50
CreateArray_Loop:
	slt $t2, $a1, $t1 #i < 50?
	beq $t2, $0, Exit_Loop #if not then exit loop
	sll $t2, $a1, 2	#$t2 = i * 4
	add $t2, $t2, $a0 # address of array[i]
	mult $a1, $t0
	mflo $t3	# $t3 = i * 3
	sw $t3, 0($t2) #save array[i]
	addi $a1, $a1, 1 #i = i + 1
	j CreateArray_Loop
Exit_Loop:
	#my code
	lw $t2, 356($0) #t2 = my_array[25]
	lw $t3, 376($0) #t3 = my_array[30]
	add $t2, $t2, $t3 #t2 = t2 + t3
	addiu $t3, $0, 30 #t3 = 30
	div $t2, $t3 # (my_array[25] + my_array[30]) / 30
	mflo $a1 # n = (my_array[25] + my_array[30]) / 30
	addi $v0, $0, 1
	jal factorial #call procedure
	add $s0, $v0, $0 #return value
	j end
factorial: addi $sp, $sp, -8 #make room on stack
	sw $a1, 4($sp) # store $a1
	sw $ra, 0($sp) # store $ra
	# your code goes in here
	addi $t4, $0, 2
	slt  $t4, $a1, $t4
	beq  $t4, $0, else
	addi $v0, $0, 1
	addi $sp, $sp, 8
	jr $ra
else:	addi $a1, $a1, -1
	jal factorial
	lw $ra, 0($sp)
	lw $a1, 4($sp)
	addi $sp, $sp, 8
	mult $v0, $a1
	mflo $v0
	jr $ra
end:	sw $a1, 0($0)
	sw $s0, 16($0)