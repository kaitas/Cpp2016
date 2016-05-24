/* 応用プログラミングA 第6回演習問題 クラスの概要(2)
　問題2: 共用体(union)
 まずは教科書p.63の例2.5の2を参考に...
  C++の共用体とは，関数とデータの両方をメンバに含むことができるクラス型．privateを使うまですべてのメンバが公開.
  なぜ「共用」と呼ぶか？それはすべてのデータメンバが同じメモリ位置を共用するため．
　すべてのデータを同じメモリアドレスで共用するようなオブジェクトはクラスでは生成できない（カプセル化）．

  なお，問題の出題内容の解説であるが，バイト(bytes)とはASCII（半角英数文字）で1文字分の単位のこと．
  char型で0～255を表現できるが，それがちょうど 1 byte．
  bitは，2進数のゼロイチの最小単位．8 bits = 1 byte なので 00000000 の形式で表示したい．
 */
#include <iostream>
using namespace std;

union bits {
	bits(int n); //教科書ではdouble
	void show_bits();
	int i; //教科書では double d
	unsigned char c[sizeof(int)]; //sizeofは与えられた型のサイズをintで返す
	// debuggerで調べてみよう！
	// cはunsigned char型配列でc[0]～c[3]までの4つ．つまり intは 4 bytes，char 4文字で表現できる．
	//unsignedはプラスマイナスの符号を取らない，という意味．例えばunsigned intならマイナスはない．
};

bits::bits(int n) {
	i = n;
}
void bits::show_bits() {
	int i, j;
	for (j = sizeof(int) - 1; j >= 0; j--) {//3,2,1,0の順に処理
		cout << "バイト単位のビットパターン" << j << ":"; 
		for (i = 128; i; i >>= 1) { //ビットシフト演算, for文の2項目はゼロでない限りtrueであり続ける．
			if (i & c[j]) {
				cout << "1";
			} else {
				cout << "0";
			}
		}
		cout << "\n";
	}
}

int main() {
	int n;
	cout << "整数を入力："; cin >> n; 
	bits ob(n);
	ob.show_bits();

	return 0;
}