#include <stdio.h>
#include <math.h>
int gcd(int a, int b);
int main() {
	while (1) {
		int a;int b;int lcm;int gcd_;
		printf("Enter a:");
		scanf_s("%d", &a);
		printf("Enter b:");
		scanf_s("%d", &b);
		gcd_ = gcd(a, b);
		lcm = a * b / gcd_;
		printf("%d,%d\n", gcd_, lcm);
	}
	return 0;
}
int gcd(int a, int b) {
	int output;
	output = b ? gcd(b, a % b) : a;
	return output;
}