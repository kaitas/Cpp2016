/*
応用プログラミングA 第4回 これまでの総合的な演習
課題3：メンバ変数とメンバ関数の確認
C言語版をまずは丸写ししましょう！
*/
#include <stdio.h>

typedef struct schedule {
	int		month;
	int	day;
	char	todo[256];
} SCHEDULE;

//SCHEDULE型の構造体のポインタで渡された構造体に対して，そのメンバ{month, day, todo}を入力させる
void input(SCHEDULE *p) {
	printf("予定を入力します\n");
	printf("何月何日の予定ですか？\n");	scanf("%d%d", &p->month, &p->day);
	printf("内容を入力してください\n");	scanf("%s", &p->todo);
}
//SCHEDULE型の構造体で渡すとその内容を表示する関数
void output(SCHEDULE p) {
	printf("%d月%d日 %s\n", p.month, p.day, p.todo);
}

int main() {
	SCHEDULE ob1, ob2;
	printf("C言語版");
	input(&ob1);
	input(&ob2);
	printf("入力されている予定\n");
	output(ob1);
	output(ob2);
	return 0;
}