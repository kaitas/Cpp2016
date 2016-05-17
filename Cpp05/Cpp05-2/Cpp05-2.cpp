/* ���p�v���O���~���OA ��5�񉉏K��� �N���X�̊T�v(1)
�@���2�F���������󂯎��R���X�g���N�^
  ��蕶���F��3�񉉏K�ō쐬�����O�p�`��\���N���XTriangle�ɁC
  �������Ƃ��ĂR�ӂ̒������󂯎��R���X�g���N�^��ǉ�����D
  �܂��C�R�ӂ̒�������ʐς��v�Z���Ė߂�l��Ԃ������o�֐�area()��ǉ��D
  ���̃N���X���e�X�g���邽�߂ɁCmain()�֐��œK���ȎO�p�`�̃I�u�W�F�N�g���쐬���C
  ���̂R�ӂ̒����Ɩʐς��o�͂���Dtest data:{a,b,c} = {3,4,5} �ʐ�=6�ƂȂ邱�ƁD
  �܂��́C��R��̃\�[�X�������Ă��ĂˁD
   */
#include<iostream>
#include<cmath>  // sqrt()�̂��߂ɓ���Ă��������C���͂Ȃ��Ă��ʂ��Ă��܂��܂����CANSI�m���Ƃ��āD
using namespace std;
/* �ȉ��͉ۑ�3-3����ė��p */
class Triangle {
	//private
	double a, b, c; //3�ӂ̒���
public: //��ʌ��J�C�O����A�N�Z�X�ł���Ƃ����Ӗ�
		//�ۑ�5-2�Ƃ��Ă͂����ɁC
		//(1)�R���X�g���N�^ Triangle() 
		//(2)�ʐς����߂� area() ��ǉ�������
	Triangle( double u, double v, double w); //�Ȃ�uvw�Ȃ̂��H���ꂪ�������Ȃ̂��I
	double area();  //���݂�3�ӂ���ʐς�double�ŕԂ��D�����͂Ȃ��D
	void set_a(double num);
	void set_b(double num);
	void set_c(double num);
	double get_a();
	double get_b();
	double get_c();
};
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
	return sqrt(s*(s-a) * (s-b) * (s-c) );
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
