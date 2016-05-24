/* 応用プログラミングA 第6回演習問題 クラスの概要(2)
 問題6-3 自動インライン化，ソースは課題5-2からもってくる．
 インライン関数については教科書p.66を参照のこと．
  関数の呼び出しと終了に伴うオーバーヘッド（負荷）が違う．速く実行できる．そのかわりプログラムが大きくなる．
  関数定義の前に inline をつけるだけ．
  自動インライン化するためには，p.70参照．クラス定義の中に関数を実装していく．inlineキーワードはつけてもよいが不要．
 */
#include<iostream>
#include<cmath>  // sqrt()のために入れてください，実はなくても通ってしまいますが，ANSI知識として．
using namespace std;
/* 以下は課題3-3から再利用 */
class Triangle {
	//private
	double a, b, c; //3辺の長さ
public:
	Triangle(double u, double v, double w) {
			a = u; b = v; c = w;    //仮引数uvwから，プライベートメンバ変数abcにデータを受け渡し
	}
	//面積を求める...ヘロンの公式を使います
	double area() {
		double s;
		s = (a + b + c) / 2.0f;
		return sqrt(s*(s - a) * (s - b) * (s - c));
	} //インライン化
	//課題6-3としてはこのアクセッサーをまずは自動インラインしていきたい
	//自動インライン化：メンバ関数の定義のセミコロンをとって，{} で実装すればよい．
	void set_a(double num) { a = num; }
	void set_b(double num) { b = num; }
	void set_c(double num) { c = num; }
	double get_a() { return a; }
	double get_b() { return b; }
	double get_c() { return c; }
};
/*課題6-3としては自動インライン化したので不要
//コンストラクタの実装
Triangle::Triangle(double u, double v, double w)
{
	a = u; b = v; c = w;    //仮引数uvwから，プライベートメンバ変数abcにデータを受け渡し
}
//面積を求める...ヘロンの公式を使います
double Triangle::area()
{
	double s;
	s = (a + b + c) / 2.0f;
	return sqrt(s*(s - a) * (s - b) * (s - c));
}
void Triangle::set_a(double num) { //★numはこの大かっこの中だけ存在できる
	a = num;
}
void Triangle::set_b(double num) {
	b = num;
}
void Triangle::set_c(double num) {
	c = num;
}
//今回のゲッターは値をdoubleで返すことに注意
double Triangle::get_a() {
	return a; //ゲッターはただ，値を返してあげればよいことが多い
}
double Triangle::get_b() {
	return b;
}
double Triangle::get_c() {
	return c;
}
*/
int main() {
	//main()でのTriangleクラスのコンストラクタはどうコールするべきなのか？
	//今回はこんな感じで呼びます
	Triangle obj(3.0, 4.0, 5.0); //まだ実装がないので赤線入り
	cout << "辺a = " << obj.get_a() << "\n";
	cout << "辺b = " << obj.get_b() << "\n";
	cout << "辺c = " << obj.get_c() << "\n";
	cout << "面積= " << obj.area() << "\n";
	return 0;
}
