/* ���p�v���O���~���OA ��6�񉉏K��� �N���X�̊T�v(2)
�@���1�F�p�����I�u�W�F�N�g�|�C���^
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
	rectangle(double h, double w); //�R���X�g���N�^�C�����ƕ����w��
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
//�ȏ�͉ۑ�5-3���玝���Ă����\�[�X�D
//������I�u�W�F�N�g�̃|�C���^�œ����悤�ɂ���
int main() {
	rectangle b(10.0, 5.0); //�����́C�l�p�Ƃ����Ӗ�
	isosceles i(4.0, 6.0); //"2����"�Ƃ����Ӗ�
   //�V���ɕʂ�rectangle,isoceles�N���X�̃I�u�W�F�N�g���u*�v�����ă|�C���^�Ő錾����
   //�Ȃ����̂�p�̓|�C���^�ł��邱�Ƃ𖼑O�Ɋ܂߂Ă���i�n���K���A����@�Ƃ������̕��@�C�n���K���[�ꂪ���̌`�炵���j
	rectangle *pb; 
	isosceles *pi; 
	pb = &b;  pi = &i; //�|�C���^���󂯓n�����ƂŁC�I�u�W�F�N�g���R�s�[�����`�ɂȂ�(���m�ɂ̓R�s�[�ł͂Ȃ��Q��)
	//�|�C���^�́u�錾����Ƃ��́��C�󂯓n���Ƃ��́��v�Ɗo���悤

  //�����̂ƎO�p�`�̍����C���C�ʐς�\������ ���ʕ\����
 /*�ۑ�5-3�̂Ƃ��͂���Ȃ��񂶂ŁC�\�����܂���
	cout << "�����`�� ����: " << b.get_h() << " ��:" << b.get_w();
	cout << " �ʐ�= " << b.area() << "\n";
	cout << "�񓙕ӎO�p�`�� ����: " << i.get_h() << " ��:" << i.get_w();
	cout << " �ʐ�= " << i.area() << "\n";
*/
	//�ۑ�6-1�Ƃ��Ă̓|�C���^���烁�\�b�h���R�[������D��̓I�ɂ̓A���[���Z�q�u->�v���g�p����I
	cout << "�����` �����F" << pb->get_h() << "�@���F" << pb->get_w() << " �ʐρF" << pb->area() << "\n";
	cout << "�O�p�` �����F" << pi->get_h() << "�@���F" << pi->get_w() << " �ʐρF" << pi->area() << "\n";
	return 0;
}