#include <stdio.h>
#include <math.h>
//�����ɖʐς����߂�֐�areatri()���`�E�������܂�
double areatri(double a, double b, double c) {
	double s;//�w�����̌����ɂ�����s�����߂Ċi�[����ϐ�
	s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c)); //������"�w�����̌���"
}
//main
int main() {
	double a, b, c;
	printf("�O�p�`�̕ӂ̒�������͂��Ă��������F");
	scanf("%lf %lf %lf", &a, &b, &c); //lf = long floating point�^(double)
	printf("�ʐς� %f �ł�\n", areatri(a,b,c));//��q�̊֐�areatri()
	return 0;
}

