/*
���p�v���O���~���OA ��4�� ����܂ł̑����I�ȉ��K
�ۑ�3�F�����o�ϐ��ƃ����o�֐��̊m�F
C����ł��܂��͊ێʂ����܂��傤�I
*/
#include <stdio.h>

typedef struct schedule {
	int		month;
	int	day;
	char	todo[256];
} SCHEDULE;

//SCHEDULE�^�̍\���̂̃|�C���^�œn���ꂽ�\���̂ɑ΂��āC���̃����o{month, day, todo}����͂�����
void input(SCHEDULE *p) {
	printf("�\�����͂��܂�\n");
	printf("���������̗\��ł����H\n");	scanf("%d%d", &p->month, &p->day);
	printf("���e����͂��Ă�������\n");	scanf("%s", &p->todo);
}
//SCHEDULE�^�̍\���̂œn���Ƃ��̓��e��\������֐�
void output(SCHEDULE p) {
	printf("%d��%d�� %s\n", p.month, p.day, p.todo);
}

int main() {
	SCHEDULE ob1, ob2;
	printf("C�����");
	input(&ob1);
	input(&ob2);
	printf("���͂���Ă���\��\n");
	output(ob1);
	output(ob2);
	return 0;
}