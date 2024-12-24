#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
void findFactor(vector<long long>& factorArray, long long num) {
	long long i = 2;
	long long fixedNum = num;
	while (i * i <= fixedNum && num != 1) {
		if (num % i == 0) {
			factorArray.push_back(i);
			num = num / i;
		}
		else {
			i++;
		}
	}
}

int main() {
	long long num;vector<long long>factorArray;
	while (1) {
		factorArray = {};
		cout << "Enter the number you want to find its factor:" << endl;
		cin >> num;
		auto start = std::chrono::high_resolution_clock::now();
		findFactor(factorArray, num);
		if (factorArray.size() == 0) {
			cout << num << " is a prime!";
		}
		else {
			cout << "Factors are:" << endl;
			for (int i = 0;i < factorArray.size();i++) {
				cout << factorArray[i] << ",";
			}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::cout << "Time cost: " << duration.count() << " ms\n";
		printf("\n");
	}
	return 0;
}
