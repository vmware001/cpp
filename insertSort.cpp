#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
        if (inserted == 0) {
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
        std::cout << "请输入数字，输入空行结束输入并排序：\n";
        std::getline(std::cin, input);
        if (input.empty()==1) { 
            break;
        }

        try {
            num = std::stoi(input);
            array.push_back(num);
        }
        catch (...) {
            std::cout << "请输入有效的整数！\n";
        }
    }    
    if (array.size() == 0) {
        std::cout << "你没有输入任何数字.\n";
        return 0;
    }
    insertSort(array);
    std::cout << "排序后的结果为：\n";
    for (int i = 0;i <= array.size() - 1;i++) {
        std::cout << array[i];
        if (i != array.size() - 1) {
            printf(",");
        }
    }
    printf("\n");
    return 0;
}
