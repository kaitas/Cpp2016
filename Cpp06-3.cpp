/* ���p�v���O���~���OA ��6�񉉏K��� �N���X�̊T�v(2)
 ���6-3 �����C�����C�����C�\�[�X�͉ۑ�5-2��������Ă���D
 �C�����C���֐��ɂ��Ă͋��ȏ�p.66���Q�Ƃ̂��ƁD
  �֐��̌Ăяo���ƏI���ɔ����I�[�o�[�w�b�h�i���ׁj���Ⴄ�D�������s�ł���D���̂����v���O�������傫���Ȃ�D
  �֐���`�̑O�� inline �����邾���D
  �����C�����C�������邽�߂ɂ́Cp.70�Q�ƁD�N���X��`�̒��Ɋ֐����������Ă����Dinline�L�[���[�h�͂��Ă��悢���s�v�D
 */
#include<iostream>
#include<cmath>  // sqrt()�̂��߂ɓ���Ă��������C���͂Ȃ��Ă��ʂ��Ă��܂��܂����CANSI�m���Ƃ��āD
using namespace std;
/* �ȉ��͉ۑ�3-3����ė��p */
class Triangle {
	//private
	double a, b, c; //3�ӂ̒���
public:
	Triangle(double u, double v, double w) {
			a = u; b = v; c = w;    //������uvw����C�v���C�x�[�g�����o�ϐ�abc�Ƀf�[�^���󂯓n��
	}
	//�ʐς����߂�...�w�����̌������g���܂�
	double area() {
		double s;
		s = (a + b + c) / 2.0f;
		return sqrt(s*(s - a) * (s - b) * (s - c));
	} //�C�����C����
	//�ۑ�6-3�Ƃ��Ă͂��̃A�N�Z�b�T�[���܂��͎����C�����C�����Ă�������
	//�����C�����C�����F�����o�֐��̒�`�̃Z�~�R�������Ƃ��āC{} �Ŏ�������΂悢�D
	void set_a(double num) { a = num; }
	void set_b(double num) { b = num; }
	void set_c(double num) { c = num; }
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
};
/*�ۑ�6-3�Ƃ��Ă͎����C�����C���������̂ŕs�v
//�R���X�g���N�^�̎���
Triangle::Triangle(double u, double v, double w)
{
	a = u; b = v; c = w;    //������uvw����C�v���C�x�[�g�����o�ϐ�abc�Ƀf�[�^���󂯓n��
}
//�ʐς����߂�...�w�����̌������g���܂�
double Triangle::area()
{
	double s;
	s = (a + b + c) / 2.0f;
	return sqrt(s*(s - a) * (s - b) * (s - c));
}
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
	return b;
}
double Triangle::get_c() {
	return c;
}
*/
int main() {
	//main()�ł�Triangle�N���X�̃R���X�g���N�^�͂ǂ��R�[������ׂ��Ȃ̂��H
	//����͂���Ȋ����ŌĂт܂�
	Triangle obj(3.0, 4.0, 5.0); //�܂��������Ȃ��̂ŐԐ�����
	cout << "��a = " << obj.get_a() << "\n";
	cout << "��b = " << obj.get_b() << "\n";
	cout << "��c = " << obj.get_c() << "\n";
	cout << "�ʐ�= " << obj.area() << "\n";
	return 0;
}
