#include<stdio.h>
#include<math.h>
int main() {
	float a;float b;float c;float delta;float x1;float x2;float re;float im;float im_2;
	printf("a=");
	scanf_s("%f", &a);
	printf("b=");
	scanf_s("%f", &b);
	printf("c=");
	scanf_s("%f", &c);
	delta = b * b - 4 * a * c;
	if (a == 0)printf("Error!!!");
	else {
		if (delta >= 0) {
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			printf("x1=%f,x2=%f", x1, x2);
		}
		if (delta < 0) {
			re = -b / (2 * a);
			im = sqrt(-delta) / (2 * a);
			im_2 = -im;
			printf("x1=%f+%f i,x2=%f%f i", re, im, re, im_2);
		}
	}
	return 0;
}