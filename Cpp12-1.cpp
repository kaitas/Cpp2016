/* 応用プログラミングA 第12回 演算子オーバーロード
問題1-3:複素数の四則演算(+,-,*,/)
*/
#include <iostream>
using namespace std;
//まずは問題文からクラスを書き写してしまいましょう
class Complex {
	double real; double imag;
public:
	Complex(double x = 0, double y = 0) { real = x; imag = y; }
	double GetReal() { return real; }
	double GetImag() { return imag; }
	void show(char *str) {
		cout << str << "(" << real << "," << imag << ")\n";
	}
	//問題1で必要となる関数宣言
	Complex operator+(Complex o);
	Complex operator-(Complex o);
	Complex operator*(Complex o);
	Complex operator/(Complex o);
	//問題2で必要となる関数宣言: 実数に対する右オペランドを宣言
	Complex operator+(double u);
	Complex operator-(double u);
	Complex operator*(double u);
	Complex operator/(double u);
	Complex operator-(); //単項演算子のマイナス
	//問題3で必要となる関数宣言（左オペランドをフレンド関数で実装する）
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
//複素数の乗算 z1 * z2 = (x1*x2 - y1*y2) + (y1*x2 + x1y2)*i
//今回の実装ではx1=real, y1=imag, x2=o.real, y2= o.imagですよね
Complex Complex::operator*(Complex o) {
	double re, im;
	re = (real * o.real - imag*o.imag);
	im = (imag * o.real + real*o.imag);
	Complex tmp(re, im);
	return tmp;
}
//複素数の除算...数学で表現した式は問題文参照してください
Complex Complex::operator/(Complex o) {
	double re, im, d;
	d = o.real*o.real + o.imag*o.imag; //分母、実はこれがゼロになると処理できない
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
//単項演算子のマイナス
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
	cout << "問題1\n複素数同士の四則演算を実装したぜ！\n";
	c = a + b;	c.show("a + b = "); 
	c = a - b;  c.show("a - b = ");
	c = a * b;  c.show("a * b = ");
	c = a / b;  c.show("a / b = ");

	cout << "\n---\n問題2\nこんどは実数xに対する右op.四則演算をやってみるぜ！\n\n";
	//★右オペランド＝その記号(演算子)の右側にパラメータがくる
	double x = 1.5;
	cout << "x = " << x << "\n";
	c = a + x; c.show(" a + x = ");
	c = a - x; c.show(" a - x = ");
	c = a * x; c.show(" a * x = ");
	c = a / x; c.show(" a / x = ");
	c = -a;    c.show("-a = ");//単項演算子のマイナス

	cout << "\n---\n問題3\nこんどは実数xに対する左op.四則演算をやってみるぜ！\n\n";
	//★左オペランド＝その記号(演算子)の左側にパラメータがくる
	c = x + a; c.show(" x + a = ");
	c = x - a; c.show(" x - a = ");
	c = x * a; c.show(" x * a = ");
	c = x / a; c.show(" x / a = ");

	return 0;
}