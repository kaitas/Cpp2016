/* ���p�v���O���~���OA ��5�񉉏K��� �N���X�̊T�v(1)
�@���4�F�u�N�v���u�ǂ��v�Łu�ȂɁv�������H
 */
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

class WordList {
	char word[50][81];
	int num;
public:
	WordList();
	void input();
	char* randomout();
};
WordList::WordList() {
	//�P�ꃊ�X�g�̏�����
	num = 0;
	srand((unsigned char)time(NULL)); //�������g������
}
void WordList::input() {
	char str[81];
	while (num < 50) {
		cout << "�P�����͂��Ă�������[end]�ŏI���";
		cin >> str;
		if (!strcmp(str, "end")) { break; }
		strcpy(word[num++], str);
	}
}
char* WordList::randomout() {
	return word[rand() % num];
}

int main() {
	WordList who, where, what;
	cout << "�P��u�N�v?";
	who.input();
	cout << "�P��u�ǂ��v?";
	where.input();
	cout << "�P��u�ȂɁv?";
	what.input();
	cout << "(����)�߂��Ⴍ����Ȃ��Ƃ����܂���H\n";
	cout << who.randomout() << " ���C " << where.randomout()
		<< " �ŁC " << what.randomout() << "���Ă��悗\n";

	return 0;
}