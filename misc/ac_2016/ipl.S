
#16bit�p�̃R�[�h
.code16gcc

.text
.global start

#------------------------------------
#�ȉ��v���O�����J�n(0000:7C00���)
start:
/* �ȉ��͂Ȃ��Ă�VM�ł͓����̂ŊO��
	#���荞�݋֎~
	cli
	
	#�Z�O�����g���W�X�^������
	xor   %ax, %ax
	mov   %ax, %ds
	mov   %ax, %es
	mov   %ax, %ss

	#�X�^�b�N�y�уt���[���|�C���^�ݒ�
	mov   $0x7BFC,%sp
	mov   %sp,%bp
	
	#���荞�݋���
	sti
*/
main_loop:
	# 2�l���擾
	callw getint
	mov   %dx,%si      # �Ԃ�lH1��%si�ɕۑ�
	callw getint
	sub   %dx,%si      # si = H1 - H2
	
	# �X�^�b�N�|�C���^�̌��ݒn���o���Ă���
	mov   %sp,%cx
	# ���s�L�������Ă����A���Ƃ�0x30�����̂ň������l������
	pushw $0xFFDD # 0x0D
	pushw $0xFFDA # 0x0A

	# %si��0�Ȃ�'0'�\�L
	jne   check_negative  # ���si-dx�Ŕ���
	pushw $0x0
	jmp   output

	# %si�����Ȃ�}�C�i�X�\�L
check_negative:
	jns   output_positive
	mov   $0x2d, %al  # AH=0x0e, AL='-' getint�̉�����ah=0x0e�̂܂�
	int   $0x10
	
	# �������]
	imul  $-1,%si
	
output_positive:
	# ���̌����珇�Ƀ������ɏ����ċt���ŏo��
	
	# ���Z��ax,dx�����g���Ȃ��̂ł�����𗘗p
	mov   %si, %ax
while_positive:  # while(%si>0)
	xor   %dx, %dx
	or    %ax, %ax  # cmp���1byte������
	je    output
	mov   $10, %si
	idiv  %si
	push  %dx       # �]����X�^�b�N�ɒǉ�
	jmp   while_positive

output:
	cmp   %sp, %cx  # while(cx>0)
	je    main_loop
	mov   $0x0e30,%ax # '0'�̕����Z
	pop   %dx
	add   %dx,%ax
	int   $0x10
	jmp   output



getint:  # %dx�ŕԂ�
	xor   %dx, %dx # �ꎞ�ϐ�

getint_while:
	# �L�[���͎擾
	xor   %ax, %ax
	int   $0x16
	
	cmp   $0x1c, %ah # ���s�L�[�Ȃ甲����
	je    getint_break

	cmp   $0x02, %ah # '1'�`'0'�̃L�[�������ȊO�̏ꍇ�ă��[�v�B
	jb    getint_while
	cmp   $0x0B, %ah
	ja    getint_while
	
	# 10�{���čŉ��ʌ���}��
	imul  $10, %dx
	# ascii�R�[�h�Ȃ̂�'0'�������A�X�L�����R�[�h(ah)���ascii�R�[�h(al)�̕����悢
	xor   %ah, %ah
	add   %ax, %dx   # ax�͉��̃��[�J���G�R�[�Ŏg���̂ŏ��������Ȃ�
	sub   $0x30,%dx
	
	# �Ȃ��Ă��������ǃ��[�J���G�R�[
	mov   $0x0e, %ah
	int   $0x10
	jmp   getint_while

getint_break:
	# ���s����(0D 0A)������
	mov   $0x0e, %ah # al�͂��Ƃ���0x0d
	int   $0x10
	mov   $0x0a, %al
	int   $0x10
	retw
