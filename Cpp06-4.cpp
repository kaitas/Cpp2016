/* ���p�v���O���~���OA ��6�񉉏K��� �N���X�̊T�v(2)
���6-4�����낭�V�~�����[�^
*/
//�}�N����`�C�Z�~�R�����s�v
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
			n = rand() % 6 + 1;//1�`6�̒l���ł�T�C�R��
			if (ob.getPosition() + n > GOAL) {
				ob.move(n - (ob.getPosition() + n - GOAL) * 2);
			}
			else {
				ob.move(n);
			}
		}
		sum += ob.getCount();
	}
	cout << GOAL << "�}�X��̃S�[���ɂ��ǂ蒅���̂�";
	cout << "����" << (double)sum / NUM << "��T�C�R����U��܂���\n";

	return 0;
}