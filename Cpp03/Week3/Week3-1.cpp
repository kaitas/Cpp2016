//�擪�s�ɂ��낢�돑�����I
// �w�Дԍ� 1234567 ����ŕF
// ���p�v���O���~���OA ��3�T C++�̊T�v
// �ۑ�1 �N���X�̊�{
// ���ȏ� p.19 �̗�1.5���...
#include <iostream>  // C����̎��� STDIO.H �̂悤�Ȃ��́D
// STDIO = Standard I/O (Input or Output)
// iostream = input / output stream ���t�@�C�����ʂ̂���
using namespace std; //���O��ԉ����ustd::�v�͈ȉ��ȗ��ł���
//�Ȃ��u::�v�̓X�R�[�v�������Z�q�Ƃ���
/// ��L��2�s�͖{���K�ɂ����Ė���̂悤�Ɏg���̂ŁC��������o���ĂˁI
class myclass {
	//����public��������Ă��Ȃ��ϐ��̐錾��...private�Ƃ������ƂɂȂ�
	int a;
	int b; //���ꂪ�ǉ����̕ϐ��D�u����J�ł���v�Ƃ������ƂȂ̂�pribate�D
public: //��ʌ��J�C�O����A�N�Z�X�ł���Ƃ����Ӗ�
	//������set/get�̓Z�b�^�[�C�Q�b�^�[�C�A�N�Z�b�T�[�ƌĂ΂�܂�
	//�Ȃ����̂悤�Ȋ֐���p�ӂ��Ȃ���΂Ȃ�Ȃ����H
	//����͂ЂƂ��ɁCprivate�ϐ����ق��̃I�u�W�F�N�g����C�ύX���ꂽ���Ȃ��̂ŁD
	void set_a(int num);
	void set_b(int num);
	int get_a();
	int get_b();
};
void myclass::set_a(int num) { //��num�͂��̑傩�����̒��������݂ł���
	a = num; //a��private�Ȃ̂ŁCmyclass::�̒������ň�����
}
void myclass::set_b(int num) { //��num�͂��̑傩�����̒��������݂ł���
	b = num; //a��private�Ȃ̂ŁCmyclass::�̒������ň�����
}
int myclass::get_a() {
	return a; //�Q�b�^�[�͂����C�l��Ԃ��Ă�����΂悢���Ƃ�����
}
int myclass::get_b() {
	return b; //���Ƃ��Δz��Ⓒ�_�������ꍇ�́C������Ɠ���ȕԂ����ɂȂ邩����
}

int main() {
	myclass ob;//ob��myclass�̎���
	ob.set_a(10);   ob.set_b(99);
	cout << ob.get_a() << "\n";
	cout << ob.get_b() << endl;
	return 0;
}


