/* ���p�v���O���~���O �ۑ�7-4 ���G�Q�[�� */
#define DEBUG_MODE 
// ��L�̃R�����g���O���΃^�[�Q�b�g�ƓG�̈ʒu���\�������i�f�o�b�O�p�j  
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAXW 4    // �}�b�v�̕� 
#define MAXH 4    // �}�b�v�̍���  
class Unit {
	int x, y;
public:
	Unit(int a, int b);
	int get_x() { return x; }
	int get_y() { return y; }
	void move_l() { if (x > 0) x--; }   // ���Ɉړ�
	void move_r() { if (x < MAXW - 1) x++; }  // �E �Ɉړ�
	void move_u() { if (y > 0) y--; }   // ��Ɉړ�
	void move_d() { if (y < MAXH - 1) y++; }  // �� �Ɉړ� 
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
	// �v���C���[�I�u�W�F�N�g�����i�����ʒu����j
	rx = rand() % MAXW;     ry = rand() % MAXH;
	Unit ply(rx, ry);
	// �^�[�Q�b�g�I�u�W�F�N�g�����i�����ʒu����j
	// �v���C���[���j�b�g�Ɠ���E���s�ɂȂ�Ȃ��悤�ɐݒ�
	do {
		rx = rand() % MAXW;
		ry = rand() % MAXH;
	} while (rx == ply.get_x() || ry == ply.get_y());
	Unit trg(rx, ry);
	// �G�l�~�[�I�u�W�F�N�g�����i�����ʒu����j
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
		cout << "���Ȃ���(" << ply.get_x() << "," << ply.get_y() << ")�ɂ��܂�\n";
#ifdef DEBUG_MODE
		cout << "�^�[�Q�b�g��(" << trg.get_x() << "," << trg.get_y() << ")�ɂ��܂�\n";
		cout << "�G1��(" << en1.get_x() << "," << en1.get_y() << ")�ɂ��܂�\n";
		cout << "�G2��(" << en2.get_x() << "," << en2.get_y() << ")�ɂ��܂�\n";
#endif
		dst = dist_unit(ply, trg);
		cout << "�^�[�Q�b�g��";
		if (dst <= 2)    // 2�}�X�ȓ��ɂ��邩����
			cout << "�߂��ɂ��܂�\n";
		else
			cout << "�߂��ɂ��܂���\n";
		dst = dist_unit(ply, en1);
		cout << "�G1��";
		if (dst <= 2)
			cout << "�߂��ɂ��܂�\n";
		else
			cout << "�߂��ɂ��܂���\n";
		dst = dist_unit(ply, en2);
		cout << "�G2��";
		if (dst <= 2)
			cout << "�߂��ɂ��܂�\n";
		else
			cout << "�߂��ɂ��܂���\n";
		do {
			cout << "�ǂ���Ɉړ����܂����H�i��-2�A�� -4�A�E-6�A��-8�A�ړ����Ȃ�-5�j:";
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
		// �^�[�Q�b�g�̈ړ�         
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
		// �G�̈ړ�         
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
		// ����
		if (dist_unit(ply, trg) == 0) {     
			cout << "���߂łƂ��I\n�^�[�Q�b�g��߂܂� �܂���\n";
			break;         
		}         
		if (dist_unit(ply, en1) == 0 || dist_unit(ply, en2) == 0) {
			cout << "�G�ɕ߂܂�܂����c\n�Q�[���I�[�o�[ \n";           
			break;         
		}     
	}  
	return 0;	
}