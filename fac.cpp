#include <iostream>
int fac(int n) {
	if (n < 0)return -1;
	if (n == 0)return 1;
	return n * fac(n - 1);
}
int main() {
	int n;
	std::cin >> n;
	std::cout << fac(n);
}
