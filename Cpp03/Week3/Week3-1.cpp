//先頭行にいろいろ書こう！
// 学籍番号 1234567 白井暁彦
// 応用プログラミングA 第3週 C++の概要
// 課題1 クラスの基本
// 教科書 p.19 の例1.5より...
#include <iostream>  // C言語の時の STDIO.H のようなもの．
// STDIO = Standard I/O (Input or Output)
// iostream = input / output stream ≒ファイルや画面のこと
using namespace std; //名前空間解決「std::」は以下省略できる
//なお「::」はスコープ解決演算子という
/// 上記の2行は本演習において毎回のように使うので，しっかり覚えてね！
class myclass {
	//特にpublicが書かれていない変数の宣言は...privateということになる
	int a;
	int b; //これが追加分の変数．「非公開である」ということなのでpribate．
public: //一般公開，外からアクセスできるという意味
	//これらのset/getはセッター，ゲッター，アクセッサーと呼ばれます
	//なぜこのような関数を用意しなければならないか？
	//それはひとえに，private変数がほかのオブジェクトから，変更されたくないので．
	void set_a(int num);
	void set_b(int num);
	int get_a();
	int get_b();
};
void myclass::set_a(int num) { //★numはこの大かっこの中だけ存在できる
	a = num; //aはprivateなので，myclass::の中だけで扱える
}
void myclass::set_b(int num) { //★numはこの大かっこの中だけ存在できる
	b = num; //aはprivateなので，myclass::の中だけで扱える
}
int myclass::get_a() {
	return a; //ゲッターはただ，値を返してあげればよいことが多い
}
int myclass::get_b() {
	return b; //たとえば配列や頂点を扱う場合は，ちょっと特殊な返し方になるかもね
}

int main() {
	myclass ob;//obはmyclassの実体
	ob.set_a(10);   ob.set_b(99);
	cout << ob.get_a() << "\n";
	cout << ob.get_b() << endl;
	return 0;
}


