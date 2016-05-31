/*
���p�v���O���~���OA ��7�T �N���X�̏ڍ�
���2�F�I�u�W�F�N�g�̃A�h���X�̊֐��ւ̈����n��
���1�Ɠ����O�p�`��\��Triangle�N���X�̃I�u�W�F�N�g�������֐�mul_tri()���쐬����B
���̊֐��́ATriangle�N���X�̃I�u�W�F�N�g�̃A�h���X��double�^�̈������󂯎��A
���̃I�u�W�F�N�g��3�ӂ̒������󂯎����double�^�̒l�{�ɂ���B
�߂�l��Ԃ��Ȃ��̂ŁA���̊֐��̌^��void�^�ł���B

 */

#include <iostream>
#include <cmath> 
using namespace std;

class Triangle {
	double a, b, c;
public:
	void set_a(double x) { a = x; }
	void set_b(double x) { b = x; }
	void set_c(double x) { c = x; }
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
	double area();
	void show();
};
//�w�����̌����ŎO�p�`�̖ʐς����߂�
double Triangle::area() {
	double s;
	s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}
//���ʂ�\������
void Triangle::show() {
	cout << "��a = " << a << "\n";
	cout << "��b = " << b << "\n";
	cout << "��c = " << c << "\n";
	cout << "�ʐ�= " << area() << "\n";
}
//�傫���ق��̖ʐς�Ԃ��֐�(�ۑ�1�̗v�_)
/* Triangle�^�̃I�u�W�F�N�g, ob1, ob2���󂯎���āA
area()�Ŕ�r���āA�傫���ق��̃I�u�W�F�N�g��߂� */
Triangle max_tri(Triangle ob1, Triangle ob2) {
	if (ob1.area() > ob2.area())
		return ob1;
	else
		return ob2;
}
//�q���g�ɏ�����Ă���֐��錾���...�O�p�`��double x�{�ɂ���
void mul_tri(Triangle *ob, double x) {
	//�|�C���^���g���Ƃ��́A�A���[���Z�q�Ń����o�ɃA�N�Z�X����
	ob->set_a(ob->get_a() * x);
	ob->set_b(ob->get_b() * x);
	ob->set_c(ob->get_c() * x);
	//���̂���return����K�v�͂Ȃ��B�|�C���^���g���ė^����ꂽ�I�u�W�F�N�g�̎��̂ɒ��ڏ����������������Ă���
	//���Ȃ݂�return���Ȃ��֐��� void�^�i�^�����j�֐��Ƃ��Đ錾���邱�Ƃɒ���
}
//�ۑ�2 main()
int main() {
	Triangle obj;
	obj.set_a(3.0); obj.set_b(4.0); obj.set_c(5.0);
	obj.show();
	cout << "���{�ɂ��܂����H\n";
	double a;	cin >> a;	//����
	//������mul_tri()�֐����R�[���A������return�Ŗ߂�l���Ƃ�̂ł͂Ȃ��A
	//Triangle�N���X�̃I�u�W�F�N�g�̃A�h���X�i���|�C���^�j��double�^�̈������󂯎����@
	//�q���g�ɏ�����Ă���֐��錾���悭���悤
	mul_tri(&obj, a); //void�^�Ȃ̂Œl�͎󂯎��Ȃ����A�|�C���^���g���Ď��̂͏����������Ă���
	obj.show();
	return 0;
}
