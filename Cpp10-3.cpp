/* ���p�v���O���~���OA ��10�񉉏K���
���3�Fnew���������������̓��I�m��
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int i, n;
	char **strlist;
	char buf[256];

	cout << "������̐�:";
	cin >> n;
	//C����̏ꍇ�ɂ͂�����sizeof()��malloc�������ă������m��
	//�����new�������܂�
	strlist = new char * [n]; //char�^�|�C���^��n���������m�ۂ��āAstrlist�ɓ����B
	//�u�������m�� = new �^ ���v�Ƃ������������A�|�C���^�^�̏ꍇ�́uchar *�v�ɂȂ邱�Ƃɒ���
	if (!strlist) { //�����������m�ۂɐ������Ȃ�������H
		cout << "���������m�ۂł��܂���";
		return 1; // �G���[�I���AOS��main�֐����[���ȊO��`���遁�G���[��`����B
	}
	cout << "������̓���\n";
	for (i = 0; i < n; i++) {
		cout << i + 1 << "��:";
		cin >> buf;
		strlist[i] = new char[strlen(buf) + 1];
		//�� new char[n������]�̃�������strlist[0]�Ɋm�ۂ��Ă���
		// �Ō��+1�͏I�[������[\0]�̂��߂ɕK�v
		if (!strlist[i]) {
			cout << "���������m�ۂł��܂���";
			return 1; // �G���[�I���AOS��main�֐����[���ȊO��`���遁�G���[��`����B
		}
		strcpy(strlist[i], buf); //buf�̓��e���m�ۂ����������ɃR�s�[
		cout << "���ׂĂ̕�����̏o��\n";
		for (i = 0; i < n; i++) {
			cout << i + 1 << "��:";
			cout << strlist[i] << "\n";
		}
	}
	return 0;
}