/* 応用プログラミングA 第5回演習問題 クラスの概要(1)
　問題3：継承
 まずは，教科書練習問題2.3をやってみること．
 */
#include <iostream>
using namespace std;

//問題文で与えられているクラス area_cl2 
class area_cl2 {
	double height, width;
public:
	void set_h(double h);
	void set_w(double w);
	double get_h(); //問題文では doubleになっていますが誤りです
	double get_w();
};
//長方形クラスは area_cl2クラスを継承している
class rectangle : public area_cl2 { //「:」コロンをつかって継承元を指定
public:
	rectangle (double h, double w); //コンストラクタ，高さと幅を指定
	double area();
};
//二等辺三角形クラスも area_cl2クラスを継承している
class isosceles : public area_cl2 { //「:」コロンをつかって継承元を指定
public:
	isosceles(double h, double w); //コンストラクタ，高さと幅を指定
	double area();
};
//以下，実装
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
//2つのクラスのコンストラクタ
rectangle::rectangle(double h, double w) {
	set_h(h); set_w(w);
}
isosceles::isosceles(double h, double w) {
	set_h(h); set_w(w);
}
//2つのクラスの面積を求める関数たち
double rectangle::area() {
	return get_h() * get_w(); //四角形の面積は 高さ×幅
}
double isosceles::area() {
	return 0.5f * get_h() * get_w(); //二等辺三角形の面積は 高さ×幅÷2
}

int main() {
	rectangle b(10.0, 5.0); //直方体，四角という意味
	isosceles i(4.0, 6.0); //"2等辺"という意味
	//直方体と三角形の高さ，幅，面積を表示する 結果表示部
	cout << "長方形の 高さ: " << b.get_h() << " 幅:" << b.get_w();
	cout << " 面積= " << b.area() << "\n";
	cout << "二等辺三角形の 高さ: " << i.get_h() << " 幅:" <<i.get_w();
	cout << " 面積= " << i.area() << "\n";
	return 0;
}