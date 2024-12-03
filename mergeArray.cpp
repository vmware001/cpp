#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char target[32767] = "This is my ";
	char add[] = "cpp homework!";
	char* output;
	output = strcat(target, add);
	printf("%s", output);
	return 0;
}
