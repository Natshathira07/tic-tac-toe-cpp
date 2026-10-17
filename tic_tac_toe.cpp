
#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    char cell = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = cell++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWinner(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        char player = 'X';
        int moves = 0;
        bool gameOver = false;

        cout << "=== TIC TAC TOE ===\n";
        cout << "Choose a cell number from 1 to 9.\n";

        while (!gameOver) {
            displayBoard();

            int choice;
            cout << "Player " << player
                 << ", enter your choice: ";

            if (!(cin >> choice) || choice < 1 || choice > 9) {
                cout << "Invalid input! Enter a number from 1 to 9.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O') {
                cout << "Cell already occupied! Try again.\n";
                continue;
            }

            board[row][col] = player;
            moves++;

            if (checkWinner(player)) {
                displayBoard();
                cout << "Player " << player << " wins!\n";
                gameOver = true;
            } else if (moves == 9) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
