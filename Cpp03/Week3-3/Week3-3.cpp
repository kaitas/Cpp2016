//�擪�s�ɂ��낢�돑�����I
// �w�Дԍ� 1234567 ����ŕF
// ���p�v���O���~���OA ��3�T C++�̊T�v
// �ۑ�3 3�p�`�N���X�̍쐬
// ���ȏ� p.19 �̗�1.5���ۑ�1���...
#include <iostream>  // C����̎��� STDIO.H �̂悤�Ȃ��́D
// STDIO = Standard I/O (Input or Output)
// iostream = input / output stream ���t�@�C�����ʂ̂���
using namespace std; //���O��ԉ����ustd::�v�͈ȉ��ȗ��ł���
					 //�Ȃ��u::�v�̓X�R�[�v�������Z�q�Ƃ���
					 /// ��L��2�s�͖{���K�ɂ����Ė���̂悤�Ɏg���̂ŁC��������o���ĂˁI
class Triangle { //�N���X���ύX���邱�Ƃɒ���
//private
	double a, b, c; //3�ӂ̒���
public: //��ʌ��J�C�O����A�N�Z�X�ł���Ƃ����Ӗ�
	void set_a(double num);
	void set_b(double num);
	void set_c(double num);
	double get_a();
	double get_b();
	double get_c();
};
void Triangle::set_a(double num) { //��num�͂��̑傩�����̒��������݂ł���
	a = num; 
}
void Triangle::set_b(double num) {
	b = num; 
}
void Triangle::set_c(double num) {
	c = num;
}
//����̃Q�b�^�[�͒l��double�ŕԂ����Ƃɒ���
double Triangle::get_a() {
	return a; //�Q�b�^�[�͂����C�l��Ԃ��Ă�����΂悢���Ƃ�����
}
double Triangle::get_b() {
	return b; //���Ƃ��Δz��Ⓒ�_�������ꍇ�́C������Ɠ���ȕԂ����ɂȂ邩����
}
double Triangle::get_c() {
	return c; //���Ƃ��Δz��Ⓒ�_�������ꍇ�́C������Ɠ���ȕԂ����ɂȂ邩����
}

int main() {
	Triangle obj;//obj��Triangle�N���X�Ƃ����^�ł͂Ȃ��C���̂��̂���
	double a, b, c;//����abc�̓N���X�̒��Ő錾���������o�ł͂Ȃ��C
	//����Ȃ邱���œ��͂̂��߂����ɂ����g��Ȃ��C�P��̕ϐ������ł��D
	cout << "�O�p�`�̕ӂ̒�������͂��Ă�������";
	cin >> a >> b >> c;
	obj.set_a(a);   obj.set_b(b);   obj.set_c(c);
	cout << "��a: " << obj.get_a() << "\n";
	cout << "��b: " << obj.get_b() << "\n";
	cout << "��c: " << obj.get_c() << "\n";
	return 0;
}


