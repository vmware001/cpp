#include <iostream>
#include <vector>
#include <string>
void insertSort(std::vector<int>& array) {
    std::vector<int> newArray;
    newArray.push_back(array[0]);
    for (int i = 1; i < array.size(); i++) {
        int inserted = 0;
        for (int j = 0; j < newArray.size(); j++) {
            if (array[i] <= newArray[j]) {
                newArray.insert(newArray.begin() + j, array[i]);
                inserted = 1;
                break;
            }
        }
        if (!inserted) {
            newArray.push_back(array[i]);
        }
    }
    array = newArray;
    return;
}
int main() {
    std::vector<int> array;
    std::string input;
    int num;
    while (1) {
        array = {};
        while (1) {
            std::cout << "\n请输入数字，输入\"exit\"结束输入并排序：\n";
            std::getline(std::cin, input);
            if (input == "exit") {
                break;
            }
            try {
                num = std::stoi(input);
                array.push_back(num);
            }
            catch (...) {
                std::cout << "请输入正确的数字.\n";
            }
        }
        if (array.size() == 0) {
            std::cout << "你没有输入任何数字.\n";
        }
        else {
            insertSort(array);
            std::cout << "排序后的结果为：\n";
            for (int i = 0;i <= array.size() - 1;i++) {
                std::cout << array[i];
                if (i != array.size() - 1) {
                    printf(",");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
