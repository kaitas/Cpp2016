//先頭行にいろいろ書こう！
// 学籍番号 1234567 白井暁彦
// 応用プログラミングA 第3週 C++の概要
// 課題3 3角形クラスの作成
// 教科書 p.19 の例1.5＆課題1より...
#include <iostream>  // C言語の時の STDIO.H のようなもの．
// STDIO = Standard I/O (Input or Output)
// iostream = input / output stream ≒ファイルや画面のこと
using namespace std; //名前空間解決「std::」は以下省略できる
					 //なお「::」はスコープ解決演算子という
					 /// 上記の2行は本演習において毎回のように使うので，しっかり覚えてね！
class Triangle { //クラス名変更することに注意
//private
	double a, b, c; //3辺の長さ
public: //一般公開，外からアクセスできるという意味
	void set_a(double num);
	void set_b(double num);
	void set_c(double num);
	double get_a();
	double get_b();
	double get_c();
};
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
	return b; //たとえば配列や頂点を扱う場合は，ちょっと特殊な返し方になるかもね
}
double Triangle::get_c() {
	return c; //たとえば配列や頂点を扱う場合は，ちょっと特殊な返し方になるかもね
}

int main() {
	Triangle obj;//objはTriangleクラスという型ではなく，実体そのもの
	double a, b, c;//このabcはクラスの中で宣言したメンバではなく，
	//たんなるここで入力のためだけにしか使わない，単一の変数たちです．
	cout << "三角形の辺の長さを入力してください";
	cin >> a >> b >> c;
	obj.set_a(a);   obj.set_b(b);   obj.set_c(c);
	cout << "辺a: " << obj.get_a() << "\n";
	cout << "辺b: " << obj.get_b() << "\n";
	cout << "辺c: " << obj.get_c() << "\n";
	return 0;
}


