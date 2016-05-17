/* ���p�v���O���~���OA ��5�񉉏K��� �N���X�̊T�v(1)
�@���3�F�p��
 �܂��́C���ȏ����K���2.3������Ă݂邱�ƁD
 */
#include <iostream>
using namespace std;

//��蕶�ŗ^�����Ă���N���X area_cl2 
class area_cl2 {
	double height, width;
public:
	void set_h(double h);
	void set_w(double w);
	double get_h(); //��蕶�ł� double�ɂȂ��Ă��܂������ł�
	double get_w();
};
//�����`�N���X�� area_cl2�N���X���p�����Ă���
class rectangle : public area_cl2 { //�u:�v�R�����������Čp�������w��
public:
	rectangle (double h, double w); //�R���X�g���N�^�C�����ƕ����w��
	double area();
};
//�񓙕ӎO�p�`�N���X�� area_cl2�N���X���p�����Ă���
class isosceles : public area_cl2 { //�u:�v�R�����������Čp�������w��
public:
	isosceles(double h, double w); //�R���X�g���N�^�C�����ƕ����w��
	double area();
};
//�ȉ��C����
void area_cl2::set_h(double h) {
	height = h;
}
void area_cl2::set_w(double w) {
	width = w;
}
double area_cl2::get_h() {
	return height;
}
double area_cl2::get_w() {
	return width;
}
//2�̃N���X�̃R���X�g���N�^
rectangle::rectangle(double h, double w) {
	set_h(h); set_w(w);
}
isosceles::isosceles(double h, double w) {
	set_h(h); set_w(w);
}
//2�̃N���X�̖ʐς����߂�֐�����
double rectangle::area() {
	return get_h() * get_w(); //�l�p�`�̖ʐς� �����~��
}
double isosceles::area() {
	return 0.5f * get_h() * get_w(); //�񓙕ӎO�p�`�̖ʐς� �����~����2
}

int main() {
	rectangle b(10.0, 5.0); //�����́C�l�p�Ƃ����Ӗ�
	isosceles i(4.0, 6.0); //"2����"�Ƃ����Ӗ�
	//�����̂ƎO�p�`�̍����C���C�ʐς�\������ ���ʕ\����
	cout << "�����`�� ����: " << b.get_h() << " ��:" << b.get_w();
	cout << " �ʐ�= " << b.area() << "\n";
	cout << "�񓙕ӎO�p�`�� ����: " << i.get_h() << " ��:" <<i.get_w();
	cout << " �ʐ�= " << i.area() << "\n";
	return 0;
}