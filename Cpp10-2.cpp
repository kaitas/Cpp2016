/* ���p�v���O���~���OA ��10�񉉏K���
���2�F�l�n���A�|�C���^�n���A�Q�Ɠn���B
*/

#include <iostream>
using namespace std;

class Coord {
	double x, y, z;
public:
	void set(double u, double v, double w) {
		x = u; y = v; z = w;
	}
	void show(); 
};

void Coord::show() {
	cout << "(" << x << "," << y << "," << z << ")";
}

//�l�n��
void setCoord1(Coord ob) {
	double u, v, w;
	cout << "������2���͂��Ă�������";
	cin >> u >> v >> w;
	ob.set(u, v, w);// ���ۂɂ͒l��ݒ�ł��Ȃ�
}
//�|�C���^�n��
void setCoord2(Coord *ob) {  //�u�|�C���^�n���v&�œn���āA*�Ŏ󂯂�
	double u, v, w;
	cout << "������2���͂��Ă�������";
	cin >> u >> v >> w;
	ob->set(u, v, w);// �I�u�W�F�N�g�̃|�C���^����̓A���[���Z�q�Ń��\�b�h���Ă�
}
//�Q�Ɠn��
void setCoord3(Coord &ob) {//�Q�Ɠn���́u&�Ŏ󂯂�v�I
	double u, v, w;
	cout << "������2���͂��Ă�������";
	cin >> u >> v >> w;
	ob.set(u, v, w);// ���ۂɂ͒l��ݒ�ł��Ȃ�
}

int main() {
	Coord obj;
	obj.set(1.1, 2.3, 5.5);
	cout << "�I�u�W�F�N�g�̏����l";
	obj.show();
	cout << "\n\n";

	//�l�n��
	cout << "�l�n���Ŋ֐��ɃI�u�W�F�N�g��n��\n";
	setCoord1(obj);//�l�n��
	cout << "�I�u�W�F�N�g�̒l:";
	obj.show();
	cout << "\n\n";

	//�|�C���^�n��
	cout << "�|�C���^�n���Ŋ֐��ɃI�u�W�F�N�g��n��\n";
	setCoord2(&obj);//�|�C���^�n��
	cout << "�I�u�W�F�N�g�̒l:";
	obj.show();
	cout << "\n\n";

	//�Q�Ɠn��
	cout << "�Q�Ɠn���Ŋ֐��ɃI�u�W�F�N�g��n��\n";
	setCoord3(obj);//�Q�Ɠn���͒l�n���ƌ����ڂ��ς��Ȃ��I�Ƃ������Ƃɒ���
	cout << "�I�u�W�F�N�g�̒l:";
	obj.show();
	cout << "\n\n";

	return 0;
}

