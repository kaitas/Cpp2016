#include <stdio.h>
#include <math.h>
//ここに面積を求める関数areatri()を定義・実装します
double areatri(double a, double b, double c) {
	double s;//ヘロンの公式におけるsを求めて格納する変数
	s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c)); //ここが"ヘロンの公式"
}
//main
int main() {
	double a, b, c;
	printf("三角形の辺の長さを入力してください：");
	scanf("%lf %lf %lf", &a, &b, &c); //lf = long floating point型(double)
	printf("面積は %f です\n", areatri(a,b,c));//上述の関数areatri()
	return 0;
}

