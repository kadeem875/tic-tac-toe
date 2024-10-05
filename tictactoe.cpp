#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "Current Board: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;
    }
}

// Function to check if there's a winner
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}

// Function to check if the board is full (draw condition)
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

// Main game function
int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;
    bool gameWon = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    
    while (!gameWon && !isBoardFull(board)) {
        displayBoard(board);
        cout << "Player " << player << ", enter your move (row and column: 1 2 or 2 3): ";
        cin >> row >> col;

        // Validate input
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Place the player's mark on the board
        board[row - 1][col - 1] = player;

        // Check if the current player has won
        if (checkWin(board, player)) {
            gameWon = true;
            displayBoard(board);
            cout << "Player " << player << " wins!" << endl;
        } else {
            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    if (!gameWon) {
        displayBoard(board);
        cout << "It's a draw!" << endl;
    }

    return 0;
}