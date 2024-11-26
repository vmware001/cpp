#include <stdio.h>
int main() {
	int r10, r20, r50;int i = 0;
	for (r50 = 0;r50 <= 2;r50++) {
		for (r20 = 0;r20 <= 5;r20++) {
			for (r10 = 0;r10 <= 10;r10++) {
				if (10 * r10 + 20 * r20 + 50 * r50 == 100)i++;
			}
		}
	}
	printf("%d", i);
}