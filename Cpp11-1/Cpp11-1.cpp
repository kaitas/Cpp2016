/* ���p�v���O���~���OA ��11�� �֐��I�[�o�[���[�h
���1 �R���X�g���N�^�֐��̃I�[�o�[���[�h

�������\�� strtype �N���X���쐬����B
���̃N���X��2�̃R���X�g���N�^�����B1�͕�������󂯎���Ă��̕�������������Ɋi�[����R���X�g���N�^�B
������͕�������󂯎���āA���̕�����Ɛ����l���󂯎���āA�����l�̒l�����J��Ԃ��ꂽ��������������Ɋi�[����R���X�g���N�^�B

*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class strtype {

	char *p;
public:
	strtype( char *s );
	strtype( char *s, int n );
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
int main() {
	strtype s1("Good!");
	strtype s2("Good!", 5); //�����ő�2������^����Ƃ��̉񐔌J��Ԃ��Ċi�[
	cout << "s1:" << s1.get() << "\n";
	cout << "s2:" << s2.get() << "\n";
	return 0;
}