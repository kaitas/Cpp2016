/*
応用プログラミングA 第4回 これまでの総合的な演習
課題3：メンバ変数とメンバ関数の確認
C++版
*/
#include <iostream>
using namespace std;

//typedef struct schedule を ヒントのclass宣言に書き換える！
class schedule {
	//特にpublic等の宣言がない場合はprivateです．ほかのクラスから直接アクセスはできません．
	int		month;
	int		day;
	char	todo[256];
public:
	void input();
	void output();

}; //構造体とは違い，一番後ろに型の名前を入れる必要はないことに注意

//クラスと構造体の違い！
// 関数の実装時に，void(型名)と関数名の間にクラス名とスコープ解決子を書く
void schedule::input() {
	cout << "予定を入力します\n";
	cout << "何月何日の予定ですか？\n";
    cin >> month >> day;
	cout << "内容を入力してください\n";
    cin >> todo;
}
void schedule::output() {
	cout << month << "月" << day << "日"<< todo << "\n";
}

int main() {
	schedule ob1, ob2;
	cout << "C++版の動作です\n";
	ob1.input();
	ob2.input();
	cout << "入力されている予定\n";
	ob1.output();
	ob2.output();
	return 0;
}