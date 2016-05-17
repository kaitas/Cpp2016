/* 応用プログラミングA 第5回演習問題 クラスの概要(1)
　問題2：仮引数を受け取るコンストラクタ
  問題文より：第3回演習で作成した三角形を表すクラスTriangleに，
  仮引数として３辺の長さを受け取るコンストラクタを追加する．
  また，３辺の長さから面積を計算して戻り値を返すメンバ関数area()を追加．
  このクラスをテストするために，main()関数で適当な三角形のオブジェクトを作成し，
  その３辺の長さと面積を出力せよ．test data:{a,b,c} = {3,4,5} 面積=6となること．
  まずは，第３回のソースをもってきてね．
   */
#include<iostream>
#include<cmath>  // sqrt()のために入れてください，実はなくても通ってしまいますが，ANSI知識として．
using namespace std;
/* 以下は課題3-3から再利用 */
class Triangle {
	//private
	double a, b, c; //3辺の長さ
public: //一般公開，外からアクセスできるという意味
		//課題5-2としてはここに，
		//(1)コンストラクタ Triangle() 
		//(2)面積を求める area() を追加したい
	Triangle( double u, double v, double w); //なぜuvwなのか？それが仮引数なのだ！
	double area();  //現在の3辺から面積をdoubleで返す．引数はなし．
	void set_a(double num);
	void set_b(double num);
	void set_c(double num);
	double get_a();
	double get_b();
	double get_c();
};
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
	return sqrt(s*(s-a) * (s-b) * (s-c) );
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
