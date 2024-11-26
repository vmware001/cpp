#include <stdio.h>
int main() {
    while (1){
        int choice;
        printf("主菜单\n");
        printf("1--------汉字\n");
        printf("2--------拼音\n");
        printf("3--------英文\n");
        printf("请输入您的选择(1/2/3): ");
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