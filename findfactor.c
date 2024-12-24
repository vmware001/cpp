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
        if (state != 0) {
            if (num < 0) {
                printf("The number you entered can not be negative!");
            }
            if (num == 0) {
                printf("The number you entered can not be zero!");
            }
        }
        if (state == 0) {
            if (factorArray[0] == num) {
                printf("The number you entered is a prime!");
            }
            else {
                for (int i = 0; i <= arrayLength - 1 && factorArray[i] != 0; i++) {
                    printf("%lld", factorArray[i]);
                    if (factorArray[i + 1] != 0) {
                        printf(", ");
                    }
                }
            }

        }
        printf("\n\n");
    }
    return 0;
}

int findFactor(long long num, long long* factorArray) {
    long long i;int j;
    if (num <= 0) {
        return -1;
    }
    long long fixedNum = num;
    for (i = 2, j = 0; i * i <= fixedNum;) {
        if (num % i == 0) {
            factorArray[j] = i;
            j++;
            num = num / i;
        }
        else {
            i++;
        }
    }
    if (num != 1) {
        factorArray[j] = num;
    }
    return 0;
}

void initArray(long long* array, int length) {
    for (int i = 0; i <= length - 1; i++) {
        array[i] = 0;
    }
}

/*以下的代码使用了素数筛算法，但是由于在输入一个很大的数时，程序要不断遍历小于这个数的整数以判断这个数是不是素数，导致程序
运行时间过长，算法效率过低，故舍弃
*/
//#include <stdio.h>
//#include <stdbool.h>
//#define arrayLength 1024
//
//int main() {
//    while (1) {
//        int findFactor(long long num, long long* factorArray);
//        void initArray(long long* array, int length);
//        long long factorArray[arrayLength];
//        long long num; 
//        initArray(factorArray, arrayLength);
//        printf("Enter the number you want to find its factor: ");
//        scanf_s("%lld", &num); 
//        int state = findFactor(num, factorArray);
//        if (state!= 0) {
//            if (num < 0) {
//                printf("The number you entered can not be negative!\n\n");
//            }
//            if (num == 0) {
//                printf("The number you entered can not be zero!\n\n");
//            }
//        }
//        if (state == 0) {
//            if (factorArray[0] == 0) {
//                printf("The number you entered is a prime!\n");
//            }
//            for (int i = 0; i <= arrayLength - 1 && factorArray[i] != 0; i++) {
//                printf("%lld", factorArray[i]); 
//                if (factorArray[i + 1] != 0) {
//                    printf(", ");
//                }
//            }
//            printf("\n\n");
//        }
//    }
//    return 0;
//}
//
//int findFactor(long long num, long long* factorArray) { 
//    long long i;int j;
//    long long prime[arrayLength];
//    void findPrime(long long* primeArray, long long max);
//    findPrime(prime, num);
//    if (num <= 0) {
//        return -1;
//    }
//    long long fixedNum = num; 
//    for (i = 0, j = 0; i * i <= fixedNum && j <= arrayLength;) {
//        if (num % prime[i] == 0) {
//            factorArray[j] = prime[i];
//            j++;
//            num = num / prime[i];
//        }
//        else {
//            i++;
//        }
//    }
//    return 0;
//}
//
//void initArray(long long* array, int length) {
//    for (int i = 0; i <= length - 1; i++) {
//        array[i] = 0;
//    }
//}
//
//void findPrime(long long* primeArray, long long max) {
//
//    int index = 0;
//    bool isPrime[arrayLength]; 
//    for (long long i = 0; i <= max; i++) {
//        isPrime[i] = true;
//    }
//    if (max >= 0) isPrime[0] = false;
//    if (max >= 1) isPrime[1] = false;
//    for (long long i = 2; i * i <= max; i++) {
//        if (isPrime[i] == true) {
//            for (long long j = i * i; j <= max; j=j+i) {
//                isPrime[j] = false;
//            }
//        }
//    }
//    for (long long i = 2; i <= max && index < arrayLength; i++) {
//        if (isPrime[i]) {
//            primeArray[index++] = i;
//        }
//    }
//}
