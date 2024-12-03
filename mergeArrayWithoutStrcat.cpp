#include <stdio.h>
#include <string.h>
int main() {
	char str1[] = "This is my ";
	char str2[] = "cpp homework!";
	char str3[32767];
	for (int i = 0;i <= strlen(str1);i++) {
		str3[i] = str1[i];
	}
	for (int i = 0;i <= strlen(str2);i++) {
		str3[i+strlen(str1)+1] = str2[i];
	}
	for (int i = 0;i <= strlen(str1) + strlen(str2);i++) {
		printf("%c", str3[i]);
	}
	printf("\n");
	return 0;
}
