/*
���p�v���O���~���OA ��4�� ����܂ł̑����I�ȉ��K
�ۑ�3�F�����o�ϐ��ƃ����o�֐��̊m�F
C++��
*/
#include <iostream>
using namespace std;

//typedef struct schedule �� �q���g��class�錾�ɏ���������I
class schedule {
	//����public���̐錾���Ȃ��ꍇ��private�ł��D�ق��̃N���X���璼�ڃA�N�Z�X�͂ł��܂���D
	int		month;
	int		day;
	char	todo[256];
public:
	void input();
	void output();

}; //�\���̂Ƃ͈Ⴂ�C��Ԍ��Ɍ^�̖��O������K�v�͂Ȃ����Ƃɒ���

//�N���X�ƍ\���̂̈Ⴂ�I
// �֐��̎������ɁCvoid(�^��)�Ɗ֐����̊ԂɃN���X���ƃX�R�[�v�����q������
void schedule::input() {
	cout << "�\�����͂��܂�\n";
	cout << "���������̗\��ł����H\n";
    cin >> month >> day;
	cout << "���e����͂��Ă�������\n";
    cin >> todo;
}
void schedule::output() {
	cout << month << "��" << day << "��"<< todo << "\n";
}

int main() {
	schedule ob1, ob2;
	cout << "C++�ł̓���ł�\n";
	ob1.input();
	ob2.input();
	cout << "���͂���Ă���\��\n";
	ob1.output();
	ob2.output();
	return 0;
}