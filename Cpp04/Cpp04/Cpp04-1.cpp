/*
���p�v���O���~���OA ��4�� ����܂ł̑����I�ȉ��K
�ۑ�1�F�֐��̃I�[�o�[���[�h
*/

#include <iostream>
using namespace std;

//�֐����������񗈂�Ƃ��C����̂悤�ɕ����̓����̊֐�������ƁC
//�R���p�C���⃊���J��main���̂ǂ̊֐����ǂ̊֐��̎����ɂȂ���ׂ��Ȃ̂��킩��܂���
//�֐��̎����������O�ɁC�t�H�[�}�b�g�̐錾�����Ă����܂��傤�D

char max(char a, char b); //char��
int max(int a, int b); //int��
double max(double a, double b); //double��


char max(char a, char b) {
	//�傫���ق���return�ŕԂ�
	//if���ŏ�����ƁC�������Z�q�ŏ������2������܂��D
/*  if���̗�
	if (a > b) {
		return a;
	}
	else {
		return b;
	}*/
	//�������Z�q�u�H�v���g���ď�������C���Ȃ�Z���Ȃ�܂�
	return (a > b) ? a : b ;
	//�������Z�q�u�H�v�ŏ�������₤�C�����Ď��Ɍ����̂�true�̂Ƃ��̌��ʁC�u�F�v(�R����)��false�D
}
//�ȉ��C�I�[�o�[���[�h
//int��
int max(int a, int b) {
	return a > b ? a : b; //���̏������C�o���ĂˁI�u�������Z�q�v
}
//double��
double max(double a, double b)
{
	return a > b ? a : b; //���̏������C�o���ĂˁI�u�������Z�q�v
}

int main() {
	char c1 = 'a', c2 = 'b';
	cout << c1 << "��" << c2 << "���r���đ傫���̂�" << max(c1, c2) << "�ł�\n";
	//int, double �ɂ��Ă����l��
	int i1 = 10,  i2 = 20;
	cout << i1 << "��" << i2 << "���r���đ傫���̂�" << max(i1, i2) << "�ł�\n";
	double d1 = 1.01, d2 = 0.99;
	cout << d1 << "��" << d2 << "���r���đ傫���̂�" << max(d1, d2) << "�ł�\n";
	return 0; //main��return 0�́u����I���v��OS�ɓ`���܂�
}
