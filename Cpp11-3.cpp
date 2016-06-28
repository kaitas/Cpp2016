/* ���p�v���O���~���OA ��11�� �֐��I�[�o�[���[�h
���3 �f�t�H���g����
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class strtype {

	char *p;
public:
	strtype(char *s, int n=1);
	strtype(const strtype &o); //�R�s�[�R���X�g���N�^, const= constant(�Œ肵�ė��܂�)
	~strtype() { delete[] p; }	//�f�X�g���N�^, new�ɑ΂���delete�Ń������j��
	char *get() { return p; }
};

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
strtype::strtype(const strtype &o) {
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
	char c, s[10];
	int n;
	cout << "������s1��ݒ肵�܂��B\n���������͂��Ă��������F";
	cin >> s;
	strtype s1(s);
	cout << "�J��Ԃ�������s2��ݒ肵�܂��B\n���������͂��Ă��������F";
	cin >> s;
	cout << "�J��Ԃ��񐔂���͂��Ă�������:";
	cin >> n;
	strtype s2(s, n);
	cout << "������s1��s2�Ɋ܂܂�邠�镶���̐��𐔂��܂��B\n��������͂��Ă��������F";
	cin >> c;
	cout << "s1��" << c << "�̐�: " << ccount(s1, c) << "\n";
	cout << "s2��" << c << "�̐�: " << ccount(s2, c) << "\n";
	cout << "s1:" << s1.get() << "\n";
	cout << "s2:" << s2.get() << "\n";
	return 0;
}