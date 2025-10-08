#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2)
            cout << "---|---|---"<<endl;
    }
    cout << endl;
}

bool checkWin(char p) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) || (board[0][i] == p && board[1][i] == p && board[2][i] == p))
            return true;

    if ((board[0][0] == p && board[1][1] == p && board[2][2] == p) || (board[0][2] == p && board[1][1] == p && board[2][0] == p))
        return true;

    return false;
}

bool boardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

int main() {
    char player = 'X';
    int row, col;

    initializeBoard();

    cout << "---- Tic-Tac-Toe ----"<<endl;
    displayBoard();

    while (true) {
        cout << "Player " << player << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position! Try again."<<endl;
            continue;
        }

        if (board[row][col] != ' ') {
            cout << "That spot is already taken!"<<endl;
            continue;
        }

        board[row][col] = player;
        displayBoard();

        if (checkWin(player)) {
            cout << "Player " << player << " wins!"<<endl;
            break;
        }

        if (boardFull()) {
            cout << "Game drawn!"<<endl;
            break;
        }
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
       
    }

    return 0;
}
