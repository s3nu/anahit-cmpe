# $a0 = array base address
# $a1 = n 
# $s0 = n! 
Main:
    addi $a0, $0, 0x100     # array base address = 0x100 
    addi $a1, $0, 0         # i = 0 
    addi $t0, $0, 3 
    addi $t1, $0, 50        # $t1 = 50 
CreateArray_Loop:
    slt $t2, $a1, $t1       # i < 50? 
    beq $t2, $0,   Exit_Loop  # if not then exit loop 
    sll $t2, $a1, 2         # $t2 = i * 4 (byte offset) 
    add $t2, $t2, $a0       # address of array[i] 
    mult $a1, $t0 
    mflo $t3                # $t3 = i * 3 
    sw $t3, 0($t2)          # save array[i] 
    addi $a1, $a1, 1        # i = i + 1 
    j CreateArray_Loop 
factorial:
    addi $sp, $sp, -8       # make room on the stack 
    sw $a1, 4($sp)          # store $a1 
    sw $ra, 0($sp)          # store $ra
    addi $v0, $0, 1
    addi $t1, $0, 1
    beq $a1, $t1, exit
    addi $a1, $a1, -1
    jal factorial
    lw $a1, 4($sp)
    multu $a1, $v0
    mflo $v0
exit:
    lw $ra, 0($sp)
    addi $sp, $sp, 8
    jr $ra
Exit_Loop:
    # your code goes in here... 
    # arithmetic calculation 
    addi $t1, $a0, 120      # address of array[30]
    lw $a1 0($t1)           # $a1 = [30]
    addi $t1, $a0, 100      # address of array[25]
    lw $t1, 0($t1)          # $t1 = [25]
    add $a1, $a1, $t1       # $a1 = $a1 + $t1
    addi $t1, $0, 30        # $t1 = 30
    divu $a1, $t1
    mflo $a1
    # factorial computation 
    jal factorial           # call procedure 
    add $s0, $v0, $0        # return value 