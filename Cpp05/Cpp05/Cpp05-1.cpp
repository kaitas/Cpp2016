/* ���p�v���O���~���OA ��5�񉉏K��� �N���X�̊T�v(1)
�@���1�F�R���X�g���N�^�ƃf�X�g���N�^

  �o��Ӑ}�F�R���X�g���N�^�ƃf�X�g���N�^�Ƃ͉��Ȃ̂��낤���H
  cout���g���āC���ۂɂ�����ʉ߂��Ă��邱�Ƃ������΂悢�D
  �o�͌��ʗ�
�@ 1: �R���X�g���N�^�Ăяo��
   2: ����main()�ł�
   3: �f�X�g���N�^�Ăяo��
  �Ƃ������ԂɂȂ邱��
 */
#include<iostream>
using namespace std;

class TestClass {
public:
	TestClass(); //�R���X�g���N�^�̒�`
	~TestClass(); //�f�X�g���N�^�̒�`�C���K��C�N���X���̑O�Ɂu~�v�i�`���_�G�ے�Chome�Ȃǂ����ȈӖ������邪�j�����܂�
};

//�R���X�g���N�^�̏�������Y��Ȃ��悤��
//�u�Ă��Ƃ��炷�@����񂱂��@�Ă��Ƃ��炷�v�C�ł��D
// �R�����R�����i::�j�X�R�[�v�����q�Ƃ����܂��D�ǂ��̖��O��Ԃ̊֐��ł��邩�𖾎����܂��D
TestClass::TestClass() {
	cout << "�R���X�g���N�^�̌Ăяo��\n";
}
//���l�Ƀf�X�g���N�^�C���Ă΂��̂��H�ɒ���
// main() return 0�̎�O����return����܂ł̊ԁC�܂肷�ׂẴI�u�W�F�N�g����������u�ԁD
// ���̃v���O�����ł͖����I�ɃI�u�W�F�N�g�̔j����R�[�����Ă��Ȃ��̂ŁC�v���O�����̏I�����ɂȂ�D
//���ۂɃf�o�b�K���g���Ċm�F���邱�ƁI�u�X�e�b�v���s�v�ł͌���܂��񂪁u�X�e�b�v�C���v����ƌ���܂��D
TestClass::~TestClass() {
	cout << "�f�X�g���N�^�Ăяo��\n";
}

int main() {
	TestClass ob;
	cout << "����main()�ł�\n";
	return 0;
}
