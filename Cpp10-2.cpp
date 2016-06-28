/* 応用プログラミングA 第10回演習問題
問題2：値渡し、ポインタ渡し、参照渡し。
*/

#include <iostream>
using namespace std;

class Coord {
	double x, y, z;
public:
	void set(double u, double v, double w) {
		x = u; y = v; z = w;
	}
	void show(); 
};

void Coord::show() {
	cout << "(" << x << "," << y << "," << z << ")";
}

//値渡し
void setCoord1(Coord ob) {
	double u, v, w;
	cout << "数字を2つ入力してください";
	cin >> u >> v >> w;
	ob.set(u, v, w);// 実際には値を設定できない
}
//ポインタ渡し
void setCoord2(Coord *ob) {  //「ポインタ渡し」&で渡して、*で受ける
	double u, v, w;
	cout << "数字を2つ入力してください";
	cin >> u >> v >> w;
	ob->set(u, v, w);// オブジェクトのポインタからはアロー演算子でメソッドを呼ぶ
}
//参照渡し
void setCoord3(Coord &ob) {//参照渡しは「&で受ける」！
	double u, v, w;
	cout << "数字を2つ入力してください";
	cin >> u >> v >> w;
	ob.set(u, v, w);// 実際には値を設定できない
}

int main() {
	Coord obj;
	obj.set(1.1, 2.3, 5.5);
	cout << "オブジェクトの初期値";
	obj.show();
	cout << "\n\n";

	//値渡し
	cout << "値渡しで関数にオブジェクトを渡す\n";
	setCoord1(obj);//値渡し
	cout << "オブジェクトの値:";
	obj.show();
	cout << "\n\n";

	//ポインタ渡し
	cout << "ポインタ渡しで関数にオブジェクトを渡す\n";
	setCoord2(&obj);//ポインタ渡し
	cout << "オブジェクトの値:";
	obj.show();
	cout << "\n\n";

	//参照渡し
	cout << "参照渡しで関数にオブジェクトを渡す\n";
	setCoord3(obj);//参照渡しは値渡しと見た目が変わらない！ということに注意
	cout << "オブジェクトの値:";
	obj.show();
	cout << "\n\n";

	return 0;
}

