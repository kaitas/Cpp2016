/* ���p�v���O���~���OA ��6�񉉏K��� �N���X�̊T�v(2)
�@���2: ���p��(union)
 �܂��͋��ȏ�p.63�̗�2.5��2���Q�l��...
  C++�̋��p�̂Ƃ́C�֐��ƃf�[�^�̗����������o�Ɋ܂ނ��Ƃ��ł���N���X�^�Dprivate���g���܂ł��ׂẴ����o�����J.
  �Ȃ��u���p�v�ƌĂԂ��H����͂��ׂẴf�[�^�����o�������������ʒu�����p���邽�߁D
�@���ׂẴf�[�^�𓯂��������A�h���X�ŋ��p����悤�ȃI�u�W�F�N�g�̓N���X�ł͐����ł��Ȃ��i�J�v�Z�����j�D

  �Ȃ��C���̏o����e�̉���ł��邪�C�o�C�g(bytes)�Ƃ�ASCII�i���p�p�������j��1�������̒P�ʂ̂��ƁD
  char�^��0�`255��\���ł��邪�C���ꂪ���傤�� 1 byte�D
  bit�́C2�i���̃[���C�`�̍ŏ��P�ʁD8 bits = 1 byte �Ȃ̂� 00000000 �̌`���ŕ\���������D
 */
#include <iostream>
using namespace std;

union bits {
	bits(int n); //���ȏ��ł�double
	void show_bits();
	int i; //���ȏ��ł� double d
	unsigned char c[sizeof(int)]; //sizeof�͗^����ꂽ�^�̃T�C�Y��int�ŕԂ�
	// debugger�Œ��ׂĂ݂悤�I
	// c��unsigned char�^�z���c[0]�`c[3]�܂ł�4�D�܂� int�� 4 bytes�Cchar 4�����ŕ\���ł���D
	//unsigned�̓v���X�}�C�i�X�̕��������Ȃ��C�Ƃ����Ӗ��D�Ⴆ��unsigned int�Ȃ�}�C�i�X�͂Ȃ��D
};

bits::bits(int n) {
	i = n;
}
void bits::show_bits() {
	int i, j;
	for (j = sizeof(int) - 1; j >= 0; j--) {//3,2,1,0�̏��ɏ���
		cout << "�o�C�g�P�ʂ̃r�b�g�p�^�[��" << j << ":"; 
		for (i = 128; i; i >>= 1) { //�r�b�g�V�t�g���Z, for����2���ڂ̓[���łȂ�����true�ł��葱����D
			if (i & c[j]) {
				cout << "1";
			} else {
				cout << "0";
			}
		}
		cout << "\n";
	}
}

int main() {
	int n;
	cout << "��������́F"; cin >> n; 
	bits ob(n);
	ob.show_bits();

	return 0;
}