#include<stdio.h>
//�����ɍ\���̂̐錾������ (typedef struct)
// �w���̃f�[�^������̂� student card -> SCARD�\���̂Ɩ��t����
typedef struct scard {
	char name[50];	//���O
	int  number;	//�w��
	int  year;		//�w�N
} SCARD; //"�^��"���ĂԂ̂�Y�ꂸ��!!(�啶�����g���̂͊��K)
		 //main
int main() {
	//�����ɍ\���̂��Ă�
	SCARD list[3]; //SCARD�^�\���̂̎��̂ł��� �z��list��錾
	int i;
	//���͕�
	for (i = 0; i < 3; i++) {
		printf("%d �l�ڂ̃f�[�^����͂��܂�\n", i+1); //�[���l�ڂ���X�^�[�g���Ȃ��悤�ɁI
		printf("�@���O����͂��Ă��������F");
		scanf("%s", list[i].name);//char�^�Ȃ̂�&�͕s�v 
		printf("�@�w�Дԍ�����͂��Ă��������F");
		scanf("%d", &list[i].number);//int�^�Ȃ̂�&�K�v
		printf("�@�w�N����͂��Ă��������F");
		scanf("%d", &list[i].year);//int�^�Ȃ̂�&�K�v
	}
	//�\����
	for (i = 0; i < 3; i++) {
		printf("�@�@�����F%s\n", list[i].name);
		printf("�w�Дԍ��F%d\n", list[i].number);
		printf("�@�@�w�N�F%d\n", list[i].year);
	}
	return 0;
}