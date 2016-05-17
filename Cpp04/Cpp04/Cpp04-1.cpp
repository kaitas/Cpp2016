/*
応用プログラミングA 第4回 これまでの総合的な演習
課題1：関数のオーバーロード
*/

#include <iostream>
using namespace std;

//関数がたくさん来るとき，今回のように複数の同名の関数が来ると，
//コンパイラやリンカはmain文のどの関数がどの関数の実装につながるべきなのかわかりません
//関数の実装を書く前に，フォーマットの宣言をしておきましょう．

char max(char a, char b); //char版
int max(int a, int b); //int版
double max(double a, double b); //double版


char max(char a, char b) {
	//大きいほうをreturnで返す
	//if文で書く例と，条件演算子で書く例の2つがあります．
/*  if文の例
	if (a > b) {
		return a;
	}
	else {
		return b;
	}*/
	//条件演算子「？」を使って書いた例，かなり短くなります
	return (a > b) ? a : b ;
	//条件演算子「？」で条件文を問う，そして次に現れるのがtrueのときの結果，「：」(コロン)でfalse．
}
//以下，オーバーロード
//int版
int max(int a, int b) {
	return a > b ? a : b; //この書き方，覚えてね！「条件演算子」
}
//double版
double max(double a, double b)
{
	return a > b ? a : b; //この書き方，覚えてね！「条件演算子」
}

int main() {
	char c1 = 'a', c2 = 'b';
	cout << c1 << "と" << c2 << "を比較して大きいのは" << max(c1, c2) << "です\n";
	//int, double についても同様に
	int i1 = 10,  i2 = 20;
	cout << i1 << "と" << i2 << "を比較して大きいのは" << max(i1, i2) << "です\n";
	double d1 = 1.01, d2 = 0.99;
	cout << d1 << "と" << d2 << "を比較して大きいのは" << max(d1, d2) << "です\n";
	return 0; //mainのreturn 0は「正常終了」をOSに伝えます
}
