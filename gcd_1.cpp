#include <math.h>
#include <stdio.h>
int gcd(int a, int b,int FactorList[]);
int main() {
	int a, b;int FactorList[32767];
	printf("Enter a:");
	scanf_s("%d", &a);
	printf("Enter b:");
	scanf_s("%d", &b);
	int gcdvalue = gcd(a, b, FactorList);
	printf("gcd=%d\n", gcdvalue);
}
int min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b, int FactorList[]) {
	int Count = 0;
	for (int i = 2;i <= min(a, b);i++) {
		if (a % i == 0 && b % i == 0) {
			Count++;
			FactorList[Count] = i;
		}
	}
	if (Count != 0)return FactorList[Count];
	return 1;
}