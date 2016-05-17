/* 応用プログラミングA 第5回演習問題 クラスの概要(1)
　問題4：「誰」が「どこ」で「なに」をした？
 */
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

class WordList {
	char word[50][81];
	int num;
public:
	WordList();
	void input();
	char* randomout();
};
WordList::WordList() {
	//単語リストの初期化
	num = 0;
	srand((unsigned char)time(NULL)); //乱数を使うお約束
}
void WordList::input() {
	char str[81];
	while (num < 50) {
		cout << "単語を入力してください[end]で終わり";
		cin >> str;
		if (!strcmp(str, "end")) { break; }
		strcpy(word[num++], str);
	}
}
char* WordList::randomout() {
	return word[rand() % num];
}

int main() {
	WordList who, where, what;
	cout << "単語「誰」?";
	who.input();
	cout << "単語「どこ」?";
	where.input();
	cout << "単語「なに」?";
	what.input();
	cout << "(りんな)めちゃくちゃなこといいますよ？\n";
	cout << who.randomout() << " が， " << where.randomout()
		<< " で， " << what.randomout() << "してたよｗ\n";

	return 0;
}