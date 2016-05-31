/*
応用プログラミングA 第7週 クラスの詳細
問題1：オブジェクトの関数への引き渡しと関数からの返し
まずは問題文にある通り、左側のクラスを書いてみよう。
右側のmainも。というかobj3しか不明な場所はありません！
*/

#include <iostream>
#include <cmath> 
using namespace std; 

class Triangle {
	double a, b, c; 
public:     
	void set_a(double x) { a = x; }     
	void set_b(double x) { b = x; }     
	void set_c(double x) { c = x; }     
	double get_a() { return a; }     
	double get_b() { return b; }     
	double get_c() { return c; }     
	double area();     
	void show();
};
//ヘロンの公式で三角形の面積を求める
double Triangle::area() {
	double s;
	s = (a + b + c) / 2;     
	return sqrt(s*(s - a)*(s - b)*(s - c));
}
//結果を表示する
void Triangle::show() { 
	cout << "辺a = " << a << "¥n";     
	cout << "辺b = " << b << "¥n";     
	cout << "辺c = " << c << "¥n";     
	cout << "面積= " << area() << "¥n"; 
}
//大きいほうの面積を返す関数(課題1の要点)
/* Triangle型のオブジェクト, ob1, ob2を受け取って、
   area()で比較して、大きいほうのオブジェクトを戻す */
Triangle max_tri(Triangle ob1, Triangle ob2) {
	if (ob1.area() > ob2.area())
		return ob1;     
	else         
		return ob2;
}

int main() {
	Triangle obj1, obj2, obj3;

	obj1.set_a(3.0);     obj1.set_b(4.0);     obj1.set_c(5.0);     
	obj2.set_a(5.0);     obj2.set_b(12.0);    obj2.set_c(13.0);
	cout << "三角形¥n";     obj1.show();
	cout << "三角形¥n";     obj2.show();
	obj3 = max_tri(obj1, obj2);   //ここが?????だったところ  
	cout << "大きい三角形¥n";     
	obj3.show();
	return 0;
}
