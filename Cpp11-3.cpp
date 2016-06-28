/* 応用プログラミングA 第11回 関数オーバーロード
問題3 デフォルト引数
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class strtype {

	char *p;
public:
	strtype(char *s, int n=1);
	strtype(const strtype &o); //コピーコンストラクタ, const= constant(固定して留まる)
	~strtype() { delete[] p; }	//デストラクタ, newに対してdeleteでメモリ破棄
	char *get() { return p; }
};

//コンストラクタその2の実装
strtype::strtype(char *s, int n) {
	int len;
	len = strlen(s)* n + 1;//その1と異なり、ここにn回分のメモリを確保させる
	p = new char[len]; //lenが正しく計算されているのであればここは変更なし
	if (!p) {
		cout << "メモリ割り当てエラー\n";
		exit(1);
	}
	*p = '\0'; //終端文字列を先に入れておく
			   //割り当てられたメモリにn回分コピーして格納
	for (int i = 0; i < n; i++) {
		strcat(p, s); //文字列sをpに表示/挿入する(strcpyだと、"Good!"が上書きされ続ける)
					  //cat = catalog copyの略。ただのコピーではなく、陳列するためにコピーするイメージ
	}
}
//コピーコンストラクタの実装
//参照させて、constを使って必要となる作業を行っているので、
//元のポインタにあるメモリに影響がない
strtype::strtype(const strtype &o) {
	int len;
	len = strlen(o.p) + 1;
	p = new char[len];
	if (!p) {
		cout << "メモリ割り当てエラー\n";
		exit(1);
	}
	*p = '\0';
	strcpy(p, o.p);
}
//指定された文字の数を数える関数
int ccount(strtype x, char c) {
	int count = 0;
	char *p;
	p = x.get();//pに文字を受け取る
	while (*p) {
		if (*p == c) count++;
		p++;//次の文字に送る
	}
	return count;
}
int main() {
	char c, s[10];
	int n;
	cout << "文字列s1を設定します。\n文字列を入力してください：";
	cin >> s;
	strtype s1(s);
	cout << "繰り返し文字列s2を設定します。\n文字列を入力してください：";
	cin >> s;
	cout << "繰り返し回数を入力してください:";
	cin >> n;
	strtype s2(s, n);
	cout << "文字列s1とs2に含まれるある文字の数を数えます。\n文字を入力してください：";
	cin >> c;
	cout << "s1の" << c << "の数: " << ccount(s1, c) << "\n";
	cout << "s2の" << c << "の数: " << ccount(s2, c) << "\n";
	cout << "s1:" << s1.get() << "\n";
	cout << "s2:" << s2.get() << "\n";
	return 0;
}