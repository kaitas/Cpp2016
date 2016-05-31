/* 応用プログラミング 課題7-4 策敵ゲーム */
#define DEBUG_MODE 
// 上記のコメントを外せばターゲットと敵の位置も表示される（デバッグ用）  
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAXW 4    // マップの幅 
#define MAXH 4    // マップの高さ  
class Unit {
	int x, y;
public:
	Unit(int a, int b);
	int get_x() { return x; }
	int get_y() { return y; }
	void move_l() { if (x > 0) x--; }   // 左に移動
	void move_r() { if (x < MAXW - 1) x++; }  // 右 に移動
	void move_u() { if (y > 0) y--; }   // 上に移動
	void move_d() { if (y < MAXH - 1) y++; }  // 下 に移動 
};
Unit::Unit(int a, int b) {
	if (a >= 0 && a < MAXW && b >= 0 && b < MAXH) {
		x = a; y = b;
	}
	else {
		x = 0; y = 0;
	}
}
int dist_unit(Unit ob1, Unit ob2) {
	return abs(ob1.get_x() - ob2.get_x())
		+ abs(ob1.get_y() - ob2.get_y());
}
int main() {
	int rx, ry, dst, drc;
	srand((unsigned int)time(NULL));
	// プレイヤーオブジェクト生成（初期位置決定）
	rx = rand() % MAXW;     ry = rand() % MAXH;
	Unit ply(rx, ry);
	// ターゲットオブジェクト生成（初期位置決定）
	// プレイヤーユニットと同列・同行にならないように設定
	do {
		rx = rand() % MAXW;
		ry = rand() % MAXH;
	} while (rx == ply.get_x() || ry == ply.get_y());
	Unit trg(rx, ry);
	// エネミーオブジェクト生成（初期位置決定）
	do {
		rx = rand() % MAXW;
		ry = rand() % MAXH;
	} while (rx == ply.get_x() || ry == ply.get_y());
	Unit en1(rx, ry);
	do {
		rx = rand() % MAXW;
		ry = rand() % MAXH;
	} while (rx == ply.get_x() || ry == ply.get_y());
	Unit en2(rx, ry);
	while (1) {
		cout << "あなたは(" << ply.get_x() << "," << ply.get_y() << ")にいます\n";
#ifdef DEBUG_MODE
		cout << "ターゲットは(" << trg.get_x() << "," << trg.get_y() << ")にいます\n";
		cout << "敵1は(" << en1.get_x() << "," << en1.get_y() << ")にいます\n";
		cout << "敵2は(" << en2.get_x() << "," << en2.get_y() << ")にいます\n";
#endif
		dst = dist_unit(ply, trg);
		cout << "ターゲットは";
		if (dst <= 2)    // 2マス以内にいるか判定
			cout << "近くにいます\n";
		else
			cout << "近くにいません\n";
		dst = dist_unit(ply, en1);
		cout << "敵1は";
		if (dst <= 2)
			cout << "近くにいます\n";
		else
			cout << "近くにいません\n";
		dst = dist_unit(ply, en2);
		cout << "敵2は";
		if (dst <= 2)
			cout << "近くにいます\n";
		else
			cout << "近くにいません\n";
		do {
			cout << "どちらに移動しますか？（下-2、左 -4、右-6、上-8、移動しない-5）:";
			cin >> drc;
		} while (drc != 2 && drc != 4 && drc != 6 && drc != 8 && drc != 5);
		switch (drc) {
		case 2:
			ply.move_d(); break;
		case 4:
			ply.move_l(); break;
		case 6:
			ply.move_r(); break;
		case 8:
			ply.move_u(); break;
		}
		// ターゲットの移動         
		drc = ((rand() % 5) + 1) * 2;
		switch (drc) {
		case 2:
			trg.move_d(); break;
		case 4:
			trg.move_l(); break;
		case 6:
			trg.move_r(); break;
		case 8:
			trg.move_u(); break;
		}
		// 敵の移動         
		drc = ((rand() % 5) + 1) * 2;
		switch (drc) {
		case 2:
			en1.move_d(); break;
		case 4:             
			en1.move_l(); break;
		case 6:
			en1.move_r(); break;         
		case 8:             
			en1.move_u(); break;
		}  
		drc = ((rand() % 5) + 1) * 2; 
		switch (drc) { 
		case 2:             
			en2.move_d(); break;
		case 4:             
			en2.move_l(); break; 
		case 6:            
			en2.move_r(); break;   
		case 8:             
			en2.move_u(); break;
		}
		// 判定
		if (dist_unit(ply, trg) == 0) {     
			cout << "おめでとう！\nターゲットを捕まえ ました\n";
			break;         
		}         
		if (dist_unit(ply, en1) == 0 || dist_unit(ply, en2) == 0) {
			cout << "敵に捕まりました…\nゲームオーバー \n";           
			break;         
		}     
	}  
	return 0;	
}