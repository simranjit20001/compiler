	.data
$str0:
	.asciiz "i = "
$str1:
	.asciiz "\n"
$str2:
	.asciiz "Ha llegado al final de la linea"
_i:
	.word 0
_x:
	.word 0
	.text
	.globl main
main:
	li $t0, 10
	sw $t0, _i
$l1:
	lw $t0, _i
	beqz $t0, $l2
	la $a0, $str0
	li $v0, 4
	syscall
	lw $t1, _i
	move $a0, $t1
	li $v0, 1
	syscall
	la $a0, $str1
	li $v0, 4
	syscall
	lw $t1, _i
	li $t2, 1
	sub $t1, $t1, $t2
	sw $t1, _i
	b $l1
$l2:
	li $t0, 10
	sw $t0, _x
	la $a0, $str2
	li $v0, 4
	syscall
	la $a0, $str1
	li $v0, 4
	syscall
	li $v0, 10
	syscall

----------------------------------------
Errores lexicos: 0
Errores sintacticos: 0
Errores semanticos: 0
