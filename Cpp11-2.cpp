/* ���p�v���O���~���OA ��11�� �֐��I�[�o�[���[�h
���2 �R�s�[�R���X�g���N�^

���1�Ƀf�X�g���N�^��ǉ�����B

*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class strtype {

	char *p;
public:
	strtype(char *s);
	strtype(char *s, int n);
	strtype(const strtype &o); //�R�s�[�R���X�g���N�^, const= constant(�Œ肵�ė��܂�)
	~strtype() { delete[] p; }	//�f�X�g���N�^, new�ɑ΂���delete�Ń������j��
	char *get() { return p; }
};
//�R���X�g���N�^����1�̎���
strtype::strtype(char *s) {
	int len;
	len = strlen(s) + 1;//str��strings�i������j�̂��ƁBcstring���C�u�����ɂ���B
	p = new char[len]; //���������m�ۂ���̂� new �^[�傫��] �Ő擪�|�C���^�擾
	if (!p) {
		cout << "���������蓖�ăG���[\n";
		exit(1);
	}
	//���蓖�Ă�ꂽ�������ɃR�s�[���Ċi�[
	strcpy(p, s); //������s��p�Ɋi�[����(p��擪�Ƃ��郁�����̈�Ɋi�[)
}
//�R���X�g���N�^����2�̎���
strtype::strtype(char *s, int n) {
	int len;
	len = strlen(s)* n + 1;//����1�ƈقȂ�A������n�񕪂̃��������m�ۂ�����
	p = new char[len]; //len���������v�Z����Ă���̂ł���΂����͕ύX�Ȃ�
	if (!p) {
		cout << "���������蓖�ăG���[\n";
		exit(1);
	}
	*p = '\0'; //�I�[��������ɓ���Ă���
			   //���蓖�Ă�ꂽ��������n�񕪃R�s�[���Ċi�[
	for (int i = 0; i < n; i++) {
		strcat(p, s); //������s��p�ɕ\��/�}������(strcpy���ƁA"Good!"���㏑�����ꑱ����)
					  //cat = catalog copy�̗��B�����̃R�s�[�ł͂Ȃ��A�񂷂邽�߂ɃR�s�[����C���[�W
	}
}
//�R�s�[�R���X�g���N�^�̎���
//�Q�Ƃ����āAconst���g���ĕK�v�ƂȂ��Ƃ��s���Ă���̂ŁA
//���̃|�C���^�ɂ��郁�����ɉe�����Ȃ�
strtype::strtype(const strtype &o){
	int len;
	len = strlen(o.p) + 1;
	p = new char[len];
	if (!p) {
		cout << "���������蓖�ăG���[\n";
		exit(1);
	}
	*p = '\0';
	strcpy(p, o.p);
}
//�w�肳�ꂽ�����̐��𐔂���֐�
int ccount(strtype x, char c) {
	int count = 0;
	char *p;
	p = x.get();//p�ɕ������󂯎��
	while (*p) {
		if (*p == c) count++;
		p++;//���̕����ɑ���
	}
	return count;
}
int main() {
	strtype s1("Good!");
	strtype s2("Good!", 5); //�����ő�2������^����Ƃ��̉񐔌J��Ԃ��Ċi�[
	cout << "s1��o�̐�" << ccount(s1, 'o') << "\n";
	cout << "s2��o�̐�" << ccount(s2, 'o') << "\n";
	cout << "s1:" << s1.get() << "\n";
	cout << "s2:" << s2.get() << "\n";
	return 0;
}