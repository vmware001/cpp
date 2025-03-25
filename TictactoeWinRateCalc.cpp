#include <iostream>
#include <random>
#include <vector>

int generateRandomInt(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}



int gameWinner(const std::vector<std::vector<int>> board) {
	for (int rows = 0;rows < 3;rows += 1) { //check row
		if (board[rows][0] == board[rows][1] && board[rows][1] == board[rows][2] && board[rows][0] != 0) return board[rows][0];
	}
	for (int cols = 0;cols < 3;cols += 1) { //check col
		if (board[0][cols] == board[1][cols] && board[1][cols] == board[2][cols] && board[0][cols] != 0) return board[0][cols];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) return board[0][2];

	for (int rows = 0;rows < 3;rows += 1) {
		for (int cols = 0;cols < 3;cols += 1) {
			if (board[rows][cols] == 0) return 0;//continue
		}
	}
	return -1;
}

int randomMoveOnce(std::vector<std::vector<int>>& board, int player) {
	while (1) {
		int rows = generateRandomInt(0, 2);
		int cols = generateRandomInt(0, 2);
		if (board[rows][cols] == 0) {
			board[rows][cols] = player;
			return 0;
		}
	}
}

int main() {
	int count = 100000;
	int player1WinCount = 0;
	int player2WinCount = 0;
	int tieCount = 0;
	int totalStep = 0;
	for (int i = 0;i < count;i++) {
		int step = 0;
		std::vector<std::vector<int>> board = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
		};
		while (1) {
			if (gameWinner(board) != 0)break;
			randomMoveOnce(board, (step % 2) + 1);
			step += 1;
		}
		if (gameWinner(board) == 1) player1WinCount += 1;
		else if (gameWinner(board) == 2) player2WinCount += 1;
		else tieCount += 1;
		totalStep += step;
	}
	double player1WinProb = static_cast<double>(player1WinCount) / count;
	double player2WinProb = static_cast<double>(player2WinCount) / count;
	double tieProb = static_cast<double>(tieCount) / count;
	double averageStep = static_cast<double>(totalStep) / count;
	std::cout << "先手获胜概率：" << player1WinProb<<std::endl;
	std::cout << "后手获胜概率：" << player2WinProb << std::endl;
	std::cout << "平局概率：" << tieProb << std::endl;
	std::cout << "平均步数：" << averageStep << std::endl;
}

