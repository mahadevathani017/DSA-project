#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool isWinner() {
    // Check rows
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter a number: ";
    cin >> choice;

    int row = (choice - 1) / SIZE;
    int col = (choice - 1) % SIZE;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move. Try again.\n";
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    while (true) {
        displayBoard();
        makeMove();

        if (isWinner()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }
    return 0;
}
