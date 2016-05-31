/*
���p�v���O���~���OA ��7�T �N���X�̏ڍ�
���3�F�֐��ƃI�u�W�F�N�g
3������Ԃ̍��W��\��Coord�N���X�B
���̌�̉ۑ�ł��g���܂��̂ł������艉�K���邱�ƁB
*/

#include <iostream>
#include <cmath> 
using namespace std;
//3������Ԃ̍��W��\��Coord�N���X
class Coord {
	double x; double y; double z;
public:
	void set_x(double u) { x = u; }
	void set_y(double v) { y = v; }
	void set_z(double w) { z = w; }
	double get_x() { return x; }
	double get_y() { return y; }
	double get_z() { return z; }
	void show();
};

void Coord::show() {
	cout << "(" << x << "," << y << "," << z << ")";
}
//���_�����߂�֐��A���Ȃ݂ɍ����Coord�N���X���̎����ł͂Ȃ�
Coord mid_Coord(Coord ob1, Coord ob2) {
	Coord ob;
	ob.set_x((ob1.get_x() + ob2.get_x()) / 2.0f);
	ob.set_y((ob1.get_y() + ob2.get_y()) / 2.0f);
	ob.set_z((ob1.get_z() + ob2.get_z()) / 2.0f);
	return ob;
}
//2�_�Ԃ̋��������߂�֐��B�������Coord�N���X���̎����ł͂Ȃ�
double dist_Coord(Coord ob1, Coord ob2) {
	//�߂�l����C�ɋ��߂邺(#include <cmath>�K�v)
	return sqrt(
  		  (ob1.get_x() - ob2.get_x()) 
		* (ob1.get_x() - ob2.get_x()) //x������2��
		+ (ob1.get_y() - ob2.get_y())
		* (ob1.get_y() - ob2.get_y()) //y������2��
		+ (ob1.get_z() - ob2.get_z())
		* (ob1.get_z() - ob2.get_z()) //z������2��
		);
}
//�ۑ�3
int main() {
	Coord p1, p2, p3;
	//�����̌��� f �� float�ł��邱�Ƃ𖾎����Ă���
	p1.set_x(1.0f);  p1.set_y(6.5f); p1.set_z(-10.0f);
	p2.set_x(-1.0f); p2.set_y(1.5f); p2.set_z(4.0f);
	cout << "�_A:"; p1.show(); cout << endl;
	cout << "�_B:"; p2.show(); cout << endl;//endl�͉��s
	p3 = mid_Coord(p1, p2); cout << "���_�F"; p3.show();
	cout << "\n 2�_�Ԃ̋����F" << dist_Coord(p1, p2) << endl;
	return 0;
}
