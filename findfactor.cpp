#include <stdio.h>
#define arrayLength 1024

int main() {
    while (1) {
        int findFactor(long long num, long long* factorArray);
        void initArray(long long* array, int length);
        long long factorArray[arrayLength];
        long long num; 
        initArray(factorArray, arrayLength);
        printf("Enter the number you want to find its factor: ");
        scanf_s("%lld", &num); 
        int state = findFactor(num, factorArray);
        if (state!= 0) {
            if (num < 0) {
                printf("The number you entered can not be negative!\n\n");
            }
            if (num == 0) {
                printf("The number you entered can not be zero!\n\n");
            }
        }
        if (state == 0) {
            if (factorArray[0] == 0) {
                printf("The number you entered is a prime!\n");
            }
            for (int i = 0; i <= arrayLength - 1 && factorArray[i] != 0; i++) {
                printf("%lld", factorArray[i]); 
                if (factorArray[i + 1] != 0) {
                    printf(", ");
                }
            }
            printf("\n\n");
        }
    }
    return 0;
}

int findFactor(long long num, long long* factorArray) { 
    long long i;int j;
    if (num <= 0) {
        return -1;
    }
    long long fixedNum = num; 
    for (i = 2, j = 0; i <= fixedNum / 2;) {
        if (num % i == 0) {
            factorArray[j] = i;
            j++;
            num = num / i;
        }
        else {
            i++;
        }
    }
    return 0;
}

void initArray(long long* array, int length) {
    for (int i = 0; i <= length - 1; i++) {
        array[i] = 0;
    }
}
