/*
応用プログラミングA 第7週 クラスの詳細
問題2：オブジェクトのアドレスの関数への引き渡し
問題1と同じ三角形を表すTriangleクラスのオブジェクトを扱う関数mul_tri()を作成する。
この関数は、Triangleクラスのオブジェクトのアドレスとdouble型の引数を受け取り、
そのオブジェクトの3辺の長さを受け取ったdouble型の値倍にする。
戻り値を返さないので、この関数の型はvoid型である。

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
//ヘロンの公式で三角形の面積を求める
double Triangle::area() {
	double s;
	s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}
//結果を表示する
void Triangle::show() {
	cout << "辺a = " << a << "\n";
	cout << "辺b = " << b << "\n";
	cout << "辺c = " << c << "\n";
	cout << "面積= " << area() << "\n";
}
//大きいほうの面積を返す関数(課題1の要点)
/* Triangle型のオブジェクト, ob1, ob2を受け取って、
area()で比較して、大きいほうのオブジェクトを戻す */
Triangle max_tri(Triangle ob1, Triangle ob2) {
	if (ob1.area() > ob2.area())
		return ob1;
	else
		return ob2;
}
//ヒントに書かれている関数宣言より...三角形をdouble x倍にする
void mul_tri(Triangle *ob, double x) {
	//ポインタを使うときは、アロー演算子でメンバにアクセスする
	ob->set_a(ob->get_a() * x);
	ob->set_b(ob->get_b() * x);
	ob->set_c(ob->get_c() * x);
	//このあとreturnする必要はない。ポインタを使って与えられたオブジェクトの実体に直接書き換え処理をしている
	//ちなみにreturnしない関数は void型（型無し）関数として宣言することに注意
}
//課題2 main()
int main() {
	Triangle obj;
	obj.set_a(3.0); obj.set_b(4.0); obj.set_c(5.0);
	obj.show();
	cout << "何倍にしますか？\n";
	double a;	cin >> a;	//入力
	//ここにmul_tri()関数をコール、ただしreturnで戻り値をとるのではなく、
	//Triangleクラスのオブジェクトのアドレス（＝ポインタ）とdouble型の引数を受け取る方法
	//ヒントに書かれている関数宣言をよく見よう
	mul_tri(&obj, a); //void型なので値は受け取らないが、ポインタを使って実体は書き換えられている
	obj.show();
	return 0;
}
