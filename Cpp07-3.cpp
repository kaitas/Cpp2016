/*
応用プログラミングA 第7週 クラスの詳細
問題3：関数とオブジェクト
3次元空間の座標を表すCoordクラス。
この後の課題でも使いますのでしっかり演習すること。
*/

#include <iostream>
#include <cmath> 
using namespace std;
//3次元空間の座標を表すCoordクラス
class Coord {
	double x; double y; double z;
public:
	void set_x(double u) { x = u; }
	void set_y(double v) { y = v; }
	void set_z(double w) { z = w; }
	double get_x() { return x; }
	double get_y() { return y; }
	double get_z() { return z; }
	void show();
};

void Coord::show() {
	cout << "(" << x << "," << y << "," << z << ")";
}
//中点を求める関数、ちなみに今回はCoordクラス内の実装ではない
Coord mid_Coord(Coord ob1, Coord ob2) {
	Coord ob;
	ob.set_x((ob1.get_x() + ob2.get_x()) / 2.0f);
	ob.set_y((ob1.get_y() + ob2.get_y()) / 2.0f);
	ob.set_z((ob1.get_z() + ob2.get_z()) / 2.0f);
	return ob;
}
//2点間の距離を求める関数。こちらもCoordクラス内の実装ではない
double dist_Coord(Coord ob1, Coord ob2) {
	//戻り値を一気に求めるぜ(#include <cmath>必要)
	return sqrt(
  		  (ob1.get_x() - ob2.get_x()) 
		* (ob1.get_x() - ob2.get_x()) //x差分の2乗
		+ (ob1.get_y() - ob2.get_y())
		* (ob1.get_y() - ob2.get_y()) //y差分の2乗
		+ (ob1.get_z() - ob2.get_z())
		* (ob1.get_z() - ob2.get_z()) //z差分の2乗
		);
}
//課題3
int main() {
	Coord p1, p2, p3;
	//数字の後ろの f は floatであることを明示している
	p1.set_x(1.0f);  p1.set_y(6.5f); p1.set_z(-10.0f);
	p2.set_x(-1.0f); p2.set_y(1.5f); p2.set_z(4.0f);
	cout << "点A:"; p1.show(); cout << endl;
	cout << "点B:"; p2.show(); cout << endl;//endlは改行
	p3 = mid_Coord(p1, p2); cout << "中点："; p3.show();
	cout << "\n 2点間の距離：" << dist_Coord(p1, p2) << endl;
	return 0;
}
