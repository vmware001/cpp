#define cnScore 90
#define mathScore 110
#define foreignScore 100

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

bool isNumber(const string& input) {
	if (input.empty()) {
		return false; 
	}
	for (char c : input) {
		if (!isdigit(c)) {
			return false; 
		}
	}
	return true; 
}

void query(int score) {
	string input;int expScore;
	while (1) {
		cout << "请输入预期分数，输入\"quit\"以退出:";
		getline(cin, input);
		cout << "\n";
		if (input == "quit") {
			system("cls");
			return;
		}
		if (!isNumber(input)) {
			system("cls");
			cout << "请检查你的输入.\n" << endl;
			continue;
		}
		expScore = stoi(input);
		cout << "你估计自己的分数为:" << expScore << "分\n" ;
		if (expScore > score) {
			cout << "不好意思，你估计的太高了!\n\n" ;
			continue;
		}
		if (expScore == score) {
			system("cls");
			cout << "你真厉害，估计的刚刚好！\n\n" ;
			return;
		}
		if (expScore < score) {
			cout << "对自己自信点，你估的太低了！\n\n" ;
			continue;
		}
	}
}

int main() {
	string choice;
	while(1){
		cout << "请输入你想要查询的科目：" << endl;
		cout << "查询语文，请输入\"cn\"。查询数学，请输入\"math\"。查询外语，请输入\"foreign\":";
		
		getline(cin, choice);
		cout << "\n";
		if (choice == "cn") {
			query(cnScore);
		}
		else if (choice == "math") {
			query(mathScore);
		}
		else if (choice == "foreign") {
			query(foreignScore);
		}
		else {
			system("cls");
			cout << "请检查你的输入\n" << endl;
		}
	}
}
