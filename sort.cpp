#include <stdio.h>
#define arrayLength 7
int main() {
	int array[arrayLength+1] = { 2,3,7,10,23,37,65 };
	int a;
	printf("Enter a:");
	scanf_s("%d", &a);
	for (int i = 0;i <= arrayLength - 1;i++) {
		if (a < array[i]) {
			for (int j = arrayLength - 1;j >= i; j--) {
				array[j + 1] = array[j];
			}
			array[i] = a;
			break;
		}
	}
	if (a >= array[arrayLength - 1]) {
		array[arrayLength] = a;
	}
	for (int i = 0;i <= arrayLength;i++) {
		printf("%d, ", array[i]);
	}
	return 0;
}
