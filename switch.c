#include <stdio.h>
int main() {
    while (1){
        int choice;
        printf("���˵�\n");
        printf("1--------����\n");
        printf("2--------ƴ��\n");
        printf("3--------Ӣ��\n");
        printf("����������ѡ��(1/2/3): ");
        scanf_s("&d", &choice);
        switch (choice) {
        case 1:
            printf("You choosed 1");
            break;
        case 2:
            printf("You choosed 2");
            break;
        case 3:
            printf("You choosed 3");
            break;
        default:
            printf("Invalid!");
            continue;
        }
    }
}