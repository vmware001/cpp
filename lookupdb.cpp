#include <iostream>
#define length 32767
long long data[length];

int main() {
    long long num;
    int i, j;
    int input();
    input();
    printf("Please Enter a number to search if it is in the database: ");
    scanf_s("%lld", &num);


    for (i = 0; i < length; i++) {  
        if (num == data[i]) {
            printf("Found %lld in the database.\n", num);
            return 0;
        }
    }


    printf("%lld can not be found in the database.\n", num); 
    return 0;
}
int input() {
    long long id;
    int i = 0;
    while (1) {
        printf("Please enter the id, enter -1 to end: ");
        scanf_s("%lld", &id); 
        if (id == -1) break;
        data[i] = id;
        i++;
    }

    return 0;
}
