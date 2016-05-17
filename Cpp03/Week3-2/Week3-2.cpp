//先頭行にいろいろ書こう！
// 学籍番号 1234567 白井暁彦
// 応用プログラミングA 第3週 C++の概要
// 課題2 C++のコンソール入力... cin, coutを使うこと!!
#include <iostream>  // C言語の時の STDIO.H のようなもの．
using namespace std; //名前空間解決「std::」は以下省略できる
//以上のヘッダは毎回の使いまわし，覚えてしまいましょう．
// 今回の課題は，関数を使えともクラスを使えとも言っていないので，mainのみで！
int main() {
	char name[50];
	int score;
	char grade;
	cout << "名前を入力してください："; //「左リダイレクト」，矢印のようなもの
	cin >> name;  //不等号の向きに注意！「右リダイレクト」と読みます
	//coutはコンソールなので，文字列をコンソールに突っ込んでいる様子「＜＜」
	//cinはキーボードなので，キーから変数に突っ込んでいる様子「＞＞」
	cout << "点数を入力してください：";
	cin >> score;
	//あとはこの点数scoreによって，gradeの判定を変える．
	//ここで使う条件分岐は何を使えばいいか？ case文では全部網羅できないよ
	if (score < 0 || score > 100) {	grade = 'X'; }
	else if (score >= 90) { grade = 'S'; }
	else if (score >= 80) { grade = 'A'; }
	else if (score >= 70) { grade = 'B'; }
	else if (score >= 60) { grade = 'C'; } 
	else { grade = 'E'; }//それ以外，つまり59～0までのひと
	cout << name << " さん の 評価は " << grade << " です \n";
	return 0;
}
