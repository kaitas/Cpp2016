/* 応用プログラミングA 第6回演習問題 クラスの概要(2)
　問題1：継承→オブジェクトポインタ
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
	rectangle(double h, double w); //コンストラクタ，高さと幅を指定
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
//以上は課題5-3から持ってきたソース．
//これをオブジェクトのポインタで動くようにする
int main() {
	rectangle b(10.0, 5.0); //直方体，四角という意味
	isosceles i(4.0, 6.0); //"2等辺"という意味
   //新たに別のrectangle,isocelesクラスのオブジェクトを「*」をつけてポインタで宣言する
   //なお名称のpはポインタであることを名前に含めている（ハンガリアン手法という名称方法，ハンガリー語がその形らしい）
	rectangle *pb; 
	isosceles *pi; 
	pb = &b;  pi = &i; //ポインタを受け渡すことで，オブジェクトをコピーした形になる(正確にはコピーではなく参照)
	//ポインタは「宣言するときは＊，受け渡すときは＆」と覚えよう

  //直方体と三角形の高さ，幅，面積を表示する 結果表示部
 /*課題5-3のときはこんなかんじで，表示しました
	cout << "長方形の 高さ: " << b.get_h() << " 幅:" << b.get_w();
	cout << " 面積= " << b.area() << "\n";
	cout << "二等辺三角形の 高さ: " << i.get_h() << " 幅:" << i.get_w();
	cout << " 面積= " << i.area() << "\n";
*/
	//課題6-1としてはポインタからメソッドをコールする．具体的にはアロー演算子「->」を使用する！
	cout << "長方形 高さ：" << pb->get_h() << "　幅：" << pb->get_w() << " 面積：" << pb->area() << "\n";
	cout << "三角形 高さ：" << pi->get_h() << "　幅：" << pi->get_w() << " 面積：" << pi->area() << "\n";
	return 0;
}