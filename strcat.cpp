#include <iostream>
#include <cstring>

void _strcat(char input1[], char input2[], char* output) {
    int i, j;
    for (i = 0; i < strlen(input1); i++) {
        output[i] = input1[i];
    }
    for (j = 0; j < strlen(input2); j++) {
        output[i + j] = input2[j]; 
    }
    output[i + j] = '\0';
}

int main() {
    char input1[32767], input2[32767];
    std::cin >> input1;
    std::cin >> input2;
    char result[65535]; 
    _strcat(input1, input2, result);
    std::cout << result << "\n";
    return 0;
}
