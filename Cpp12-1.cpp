/* ���p�v���O���~���OA ��12�� ���Z�q�I�[�o�[���[�h
���1-3:���f���̎l�����Z(+,-,*,/)
*/
#include <iostream>
using namespace std;
//�܂��͖�蕶����N���X�������ʂ��Ă��܂��܂��傤
class Complex {
	double real; double imag;
public:
	Complex(double x = 0, double y = 0) { real = x; imag = y; }
	double GetReal() { return real; }
	double GetImag() { return imag; }
	void show(char *str) {
		cout << str << "(" << real << "," << imag << ")\n";
	}
	//���1�ŕK�v�ƂȂ�֐��錾
	Complex operator+(Complex o);
	Complex operator-(Complex o);
	Complex operator*(Complex o);
	Complex operator/(Complex o);
	//���2�ŕK�v�ƂȂ�֐��錾: �����ɑ΂���E�I�y�����h��錾
	Complex operator+(double u);
	Complex operator-(double u);
	Complex operator*(double u);
	Complex operator/(double u);
	Complex operator-(); //�P�����Z�q�̃}�C�i�X
	//���3�ŕK�v�ƂȂ�֐��錾�i���I�y�����h���t�����h�֐��Ŏ�������j
	friend Complex operator+(double u, Complex o2);
	friend Complex operator-(double u, Complex o2);
	friend Complex operator*(double u, Complex o2);
	friend Complex operator/(double u, Complex o2);
};

Complex Complex::operator+(Complex o) {
	double re, im;
	re = real + o.real;
	im = imag + o.imag;
	Complex tmp(re, im);
	return tmp;
}
Complex Complex::operator-(Complex o) {
	double re, im;
	re = real - o.real;
	im = imag - o.imag;
	Complex tmp(re, im);
	return tmp;
}
//���f���̏�Z z1 * z2 = (x1*x2 - y1*y2) + (y1*x2 + x1y2)*i
//����̎����ł�x1=real, y1=imag, x2=o.real, y2= o.imag�ł����
Complex Complex::operator*(Complex o) {
	double re, im;
	re = (real * o.real - imag*o.imag);
	im = (imag * o.real + real*o.imag);
	Complex tmp(re, im);
	return tmp;
}
//���f���̏��Z...���w�ŕ\���������͖�蕶�Q�Ƃ��Ă�������
Complex Complex::operator/(Complex o) {
	double re, im, d;
	d = o.real*o.real + o.imag*o.imag; //����A���͂��ꂪ�[���ɂȂ�Ə����ł��Ȃ�
	re = (real * o.real + imag*o.imag) / d;
	im = (imag * o.real - real*o.imag) / d;
	Complex tmp(re, im);
	return tmp;
}
Complex Complex::operator+(double u) {
	double re;
	re = real + u;
	Complex tmp(re, imag);
	return tmp;
}
Complex Complex::operator-(double u) {
	double re;
	re = real - u;
	Complex tmp(re, imag);
	return tmp;
}
Complex Complex::operator*(double u) {
	double re, im;
	re = real * u;
	im = imag * u;
	Complex tmp(re, im);
	return tmp;
}
Complex Complex::operator/(double u) {
	double re, im;
	re = real / u;
	im = imag / u;
	Complex tmp(re, im);
	return tmp;
}
//�P�����Z�q�̃}�C�i�X
Complex Complex::operator-() {
	Complex tmp(-real, -imag);
	return tmp;
}
Complex operator+(double u, Complex o2) {
	double re;
	re = u + o2.real;
	Complex tmp(re, o2.imag);
	return tmp;
}
Complex operator-(double u, Complex o2) {
	double re;
	re = u - o2.real;
	Complex tmp(re, -o2.imag);
	return tmp;
}
Complex operator*(double u, Complex o2) {
	double re, im;
	re = u*o2.real;
	im = u*o2.imag;
	Complex tmp(re, im);
	return tmp;
}
Complex operator/(double u, Complex o2) {
	double re, im, d;
	d = o2.real*o2.real + o2.imag*o2.imag;
	re = u*o2.real / d;
	im =-u*o2.imag / d;
	Complex tmp(re, im);
	return tmp;
}


int main() {
	Complex a(2.0, 1.2), b(3.2, 5.0);
	Complex c;

	a.show("a = ");
	b.show("b = ");
	cout << "���1\n���f�����m�̎l�����Z�������������I\n";
	c = a + b;	c.show("a + b = "); 
	c = a - b;  c.show("a - b = ");
	c = a * b;  c.show("a * b = ");
	c = a / b;  c.show("a / b = ");

	cout << "\n---\n���2\n����ǂ͎���x�ɑ΂���Eop.�l�����Z������Ă݂邺�I\n\n";
	//���E�I�y�����h�����̋L��(���Z�q)�̉E���Ƀp�����[�^������
	double x = 1.5;
	cout << "x = " << x << "\n";
	c = a + x; c.show(" a + x = ");
	c = a - x; c.show(" a - x = ");
	c = a * x; c.show(" a * x = ");
	c = a / x; c.show(" a / x = ");
	c = -a;    c.show("-a = ");//�P�����Z�q�̃}�C�i�X

	cout << "\n---\n���3\n����ǂ͎���x�ɑ΂��鍶op.�l�����Z������Ă݂邺�I\n\n";
	//�����I�y�����h�����̋L��(���Z�q)�̍����Ƀp�����[�^������
	c = x + a; c.show(" x + a = ");
	c = x - a; c.show(" x - a = ");
	c = x * a; c.show(" x * a = ");
	c = x / a; c.show(" x / a = ");

	return 0;
}