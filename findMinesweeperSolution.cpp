#include <iostream>
#include <vector>

using namespace std;
//在这里修改行数和列数，rows为行数，cols为列数.
int rows = 5;
int cols = 5;

vector<vector<int>> knownMine(rows, vector<int>(cols, -1));
int counts = 0;

int mineCountNearby(int r, int c, const vector<vector<int>>& board) {
    int mineCount = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (r + i >= 0 && r + i < rows && c + j >= 0 && c + j < cols) {
                mineCount += board[r + i][c + j];
            }
        }
    }
    return mineCount;
}

bool isValidBoard(const vector<vector<int>>& board, const vector<vector<int>>& knownMine) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (knownMine[r][c] != -1) {
                if (mineCountNearby(r, c, board) != knownMine[r][c]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<int>>& board) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (knownMine[r][c] == -1) {
                if (board[r][c] == 0) {
                    cout << "□ ";
                }
                else {
                    cout << "X ";
                }
            }
            else {
                cout << knownMine[r][c] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void enumBoards(vector<vector<int>>& board, int index, const vector<vector<int>>& knownMine) {
    if (index == rows * cols) {
        if (isValidBoard(board, knownMine)) {
            printBoard(board);
            counts++;
        }
        return;
    }

    int r = index / cols;
    int c = index % cols;

    if (knownMine[r][c] != -1) {
        enumBoards(board, index + 1, knownMine);
        return;
    }

    board[r][c] = 0;
    enumBoards(board, index + 1, knownMine);

    board[r][c] = 1;
    enumBoards(board, index + 1, knownMine);
}

int main() {

    /*
    这是原始数据：
    knownMine[0][1] = 1;
    knownMine[0][3] = 1;
    knownMine[1][0] = 2;
    knownMine[1][1] = 2;
    knownMine[2][1] = 2;
    knownMine[2][3] = 2;
    knownMine[3][0] = 2;
    knownMine[3][1] = 3;
    knownMine[4][2] = 1;
    knownMine[4][3] = 2;
    在下方输入格子的雷数提示，knownMine[r][c]=x;表示第r+1行 第c+1列的格子，周围有x个雷，每一行末尾需要加分号";".
    */

    knownMine[0][1] = 1;
    knownMine[0][3] = 1;
    knownMine[1][0] = 2;
    knownMine[1][1] = 2;
    knownMine[2][1] = 2;
    knownMine[2][3] = 2;
    knownMine[3][0] = 2;
    knownMine[3][1] = 3;
    knownMine[4][2] = 1;
    knownMine[4][3] = 2;
    vector<vector<int>> board(rows, vector<int>(cols, 0));

    enumBoards(board, 0, knownMine);

    if (counts != 0) {
        cout << "共有" << counts << "种布局符合情况" << endl;
    }
    else {
        cout << "没有任何一种地雷布局符合情况" << endl;
    }

    return 0;
}
