#include<stdio.h>
//ここに構造体の宣言を入れる (typedef struct)
// 学生のデータを入れるので student card -> SCARD構造体と名付ける
typedef struct scard {
	char name[50];	//名前
	int  number;	//学籍
	int  year;		//学年
} SCARD; //"型名"を呼ぶのを忘れずに!!(大文字を使うのは慣習)
		 //main
int main() {
	//ここに構造体を呼ぶ
	SCARD list[3]; //SCARD型構造体の実体である 配列listを宣言
	int i;
	//入力部
	for (i = 0; i < 3; i++) {
		printf("%d 人目のデータを入力します\n", i+1); //ゼロ人目からスタートしないように！
		printf("　名前を入力してください：");
		scanf("%s", list[i].name);//char型なので&は不要 
		printf("　学籍番号を入力してください：");
		scanf("%d", &list[i].number);//int型なので&必要
		printf("　学年を入力してください：");
		scanf("%d", &list[i].year);//int型なので&必要
	}
	//表示部
	for (i = 0; i < 3; i++) {
		printf("　　氏名：%s\n", list[i].name);
		printf("学籍番号：%d\n", list[i].number);
		printf("　　学年：%d\n", list[i].year);
	}
	return 0;
}