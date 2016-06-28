/* 応用プログラミングA 第10回演習問題
問題3：newをつかったメモリの動的確保
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int i, n;
	char **strlist;
	char buf[256];

	cout << "文字列の数:";
	cin >> n;
	//C言語の場合にはここでsizeof()とmallocをつかってメモリ確保
	//今回はnewをつかいます
	strlist = new char * [n]; //char型ポインタをn個分メモリ確保して、strlistに入れる。
	//「メモリ確保 = new 型 個数」という書式だが、ポインタ型の場合は「char *」になることに注意
	if (!strlist) { //もしメモリ確保に成功しなかったら？
		cout << "メモリが確保できません";
		return 1; // エラー終了、OSにmain関数がゼロ以外を伝える＝エラーを伝える。
	}
	cout << "文字列の入力\n";
	for (i = 0; i < n; i++) {
		cout << i + 1 << "つ目:";
		cin >> buf;
		strlist[i] = new char[strlen(buf) + 1];
		//↑ new char[n文字分]のメモリをstrlist[0]に確保している
		// 最後の+1は終端文字列[\0]のために必要
		if (!strlist[i]) {
			cout << "メモリが確保できません";
			return 1; // エラー終了、OSにmain関数がゼロ以外を伝える＝エラーを伝える。
		}
		strcpy(strlist[i], buf); //bufの内容を確保したメモリにコピー
		cout << "すべての文字列の出力\n";
		for (i = 0; i < n; i++) {
			cout << i + 1 << "つ目:";
			cout << strlist[i] << "\n";
		}
	}
	return 0;
}