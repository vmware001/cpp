#include <math.h>
#include <stdio.h>
int FactorList[32767];int Count=0;
int gcd(int a, int b);
int main() {
	int a, b;
	printf("Enter a:");
	scanf_s("%d", &a);
	printf("Enter b:");
	scanf_s("%d", &b);
	int gcdvalue = gcd(a, b);
	printf("gcd=%d\n", gcdvalue);
	printf("lcm=%d\n", gcdvalue * a * b);
	printf("count=%d\n", Count);
	printf("factors are:\n");
	for (int i = 1;i <= Count;i++) {
		printf("%d\n", FactorList[i]);
	}
}
int min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b) {
	for (int i = 2;i <= min(a, b);i++) {
		if (a % i == 0 && b % i == 0) {
			Count++;
			FactorList[Count] = i;
		}
	}
	if (Count != 0)return FactorList[Count];
	return 1;
}
