#include <stdio.h>
#include <math.h>
//‚±‚±‚É–ÊÏ‚ğ‹‚ß‚éŠÖ”areatri()‚ğ’è‹`EÀ‘•‚µ‚Ü‚·
double areatri(double a, double b, double c) {
	double s;//ƒwƒƒ“‚ÌŒö®‚É‚¨‚¯‚és‚ğ‹‚ß‚ÄŠi”[‚·‚é•Ï”
	s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c)); //‚±‚±‚ª"ƒwƒƒ“‚ÌŒö®"
}
//main
int main() {
	double a, b, c;
	printf("OŠpŒ`‚Ì•Ó‚Ì’·‚³‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
	scanf("%lf %lf %lf", &a, &b, &c); //lf = long floating pointŒ^(double)
	printf("–ÊÏ‚Í %f ‚Å‚·\n", areatri(a,b,c));//ãq‚ÌŠÖ”areatri()
	return 0;
}

