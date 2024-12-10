#include <iostream>
int fac(int n) {
	if (n < 0)return -1;
	if (n == 0)return 1;
	return n * fac(n - 1);
}
int main() {
	int n, m;
	std::cout << "Enter m:\n";
	std::cin >> m;
	std::cout << "Enter n:\n";
	std::cin >> n;
	int out = fac(m) / (fac(m - n) * fac(n));
	if (m < 0 || n < 0 || (m - n) < 0)std::cout << "Please Check the number.";
	else {std::cout << out;}
	return 0;
}
