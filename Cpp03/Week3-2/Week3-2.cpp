//�擪�s�ɂ��낢�돑�����I
// �w�Дԍ� 1234567 ����ŕF
// ���p�v���O���~���OA ��3�T C++�̊T�v
// �ۑ�2 C++�̃R���\�[������... cin, cout���g������!!
#include <iostream>  // C����̎��� STDIO.H �̂悤�Ȃ��́D
using namespace std; //���O��ԉ����ustd::�v�͈ȉ��ȗ��ł���
//�ȏ�̃w�b�_�͖���̎g���܂킵�C�o���Ă��܂��܂��傤�D
// ����̉ۑ�́C�֐����g���Ƃ��N���X���g���Ƃ������Ă��Ȃ��̂ŁCmain�݂̂ŁI
int main() {
	char name[50];
	int score;
	char grade;
	cout << "���O����͂��Ă��������F"; //�u�����_�C���N�g�v�C���̂悤�Ȃ���
	cin >> name;  //�s�����̌����ɒ��ӁI�u�E���_�C���N�g�v�Ɠǂ݂܂�
	//cout�̓R���\�[���Ȃ̂ŁC��������R���\�[���ɓ˂�����ł���l�q�u�����v
	//cin�̓L�[�{�[�h�Ȃ̂ŁC�L�[����ϐ��ɓ˂�����ł���l�q�u�����v
	cout << "�_������͂��Ă��������F";
	cin >> score;
	//���Ƃ͂��̓_��score�ɂ���āCgrade�̔����ς���D
	//�����Ŏg����������͉����g���΂������H case���ł͑S���ԗ��ł��Ȃ���
	if (score < 0 || score > 100) {	grade = 'X'; }
	else if (score >= 90) { grade = 'S'; }
	else if (score >= 80) { grade = 'A'; }
	else if (score >= 70) { grade = 'B'; }
	else if (score >= 60) { grade = 'C'; } 
	else { grade = 'E'; }//����ȊO�C�܂�59�`0�܂ł̂Ђ�
	cout << name << " ���� �� �]���� " << grade << " �ł� \n";
	return 0;
}
