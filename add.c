#include <stdio.h>
int main() {
	float a, b, c;
	printf("Enter number a:");
	scanf_s("%f", &a);
	printf("Enter number b:");
	scanf_s("%f", &b);
	c = a + b;
	printf("%f", c);
}