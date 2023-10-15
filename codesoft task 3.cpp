#include <iostream>
using namespace std;


void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
bool playAgain();

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    do {
        initializeBoard(board);
        displayBoard(board);

        do {
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(board, currentPlayer, row, col)) {
                displayBoard(board);
                gameWon = checkWin(board, currentPlayer);
                gameDraw = checkDraw(board);

                if (gameWon || gameDraw) break;

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        } while (true);

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

    } while (playAgain());

    cout << "Thanks for playing! Goodbye." << endl;

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool makeMove(char board[3][3], char player, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        return false; // 
    }

    board[row][col] = player;
    return true;
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; 
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; 
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; 

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

