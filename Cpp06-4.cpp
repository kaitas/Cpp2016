/* 応用プログラミングA 第6回演習問題 クラスの概要(2)
問題6-4すごろくシミュレータ
*/
//マクロ定義，セミコロン不要
#define NUM 1000
#define GOAL 20
#include <iostream>
#include <cstdlib>
using namespace std;

class PlayerUnit {
	int position;
	int count;
public:
	PlayerUnit() {
		position = 0;
		count	 = 0;
	}
	void move(int n) {
		position += n;
		count++;
	}
	int getPosition() {
		return position;
	}
	int getCount() {
		return count;
	}
};

int main() {

	int i, n, sum = 0;
	for (i = 0; i < NUM; i++) {
		PlayerUnit ob;
		while (ob.getPosition() != GOAL) {
			n = rand() % 6 + 1;//1～6の値がでるサイコロ
			if (ob.getPosition() + n > GOAL) {
				ob.move(n - (ob.getPosition() + n - GOAL) * 2);
			}
			else {
				ob.move(n);
			}
		}
		sum += ob.getCount();
	}
	cout << GOAL << "マス先のゴールにたどり着くのに";
	cout << "平均" << (double)sum / NUM << "回サイコロを振りました\n";

	return 0;
}