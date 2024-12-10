#include <iostream>
void swap(int *p,int *q){
	int temp = *p; 
	*p = *q;
	*q = temp;
}
int main() {
	int m, n;int *p, *q;
	std::cin >> m;
	std::cin >> n;
	p = &m;
	q = &n;
	swap(p, q);
	m = *p;
	n = *q;
	std::cout << m << ","<<n;
}
