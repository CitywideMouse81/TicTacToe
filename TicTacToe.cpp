// Tic Tac Toe by CitywideMouse81

#include <iostream>
#include <utility>
#include <limits>
using namespace std;
const int SIZE = 3;

void initializeBoard(char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    cout << "+---+---+---+" << endl;
    for(int row = 0; row < SIZE; row++) {
        cout << "| ";
        for(int col = 0; col < SIZE; col++) {
            cout << board[row][col] << " | ";
        }
        cout << endl;
        cout << "+---+---+---+" << endl;
    }
}

pair<int, int> getPlayerInput() {
    int row, column;
    bool validInput = false;

    while (!validInput) {
        cout << "Enter Row (1-3): ";
        cin >> row;
        cout << "Enter Column (1-3): ";
        cin >> column;

        if (cin.fail() || row < 1 || row > 3 || column < 1 || column > 3) {
            cout << "Invalid input! Please enter numbers between 1 and 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            validInput = true;
        }
    }

    return make_pair(row, column);
}

void switchTurn(char &currentPlayer) {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

bool updateBoard(int row, int col, char player, char board[SIZE][SIZE]) {
    if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
        return false;
    }

    int rowIndex = row - 1;
    int colIndex = col - 1;

    if (board[rowIndex][colIndex] != ' ') {
        return false;
    }

    board[rowIndex][colIndex] = player;
    return true;
}

char checkRowWin(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ') {
            return board[i][0];
        }
    }
    return ' ';
}

char checkColumnsWin(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] != ' ' && 
            board[0][i] == board[1][i] && 
            board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    return ' ';
}

char checkDiagonalWin(const char board[SIZE][SIZE]) {
    if (board[0][0] != ' ' && 
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

char checkWinner(const char board[SIZE][SIZE]) {
    char winner = checkRowWin(board);
    if (winner != ' '){
        return winner;
    }

    winner = checkColumnsWin(board);
    if (winner != ' ') {
        return winner;
    }

    winner = checkDiagonalWin(board);
    if (winner != ' ') {
        return winner;
    }

    return ' ';
}

bool isBoardFull(char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void displayTieMessage(int &choice) {
    cout << "\n\n";
    cout << " ======================" << endl;
    cout << " ||                  ||" << endl;
    cout << " ||   It's a Tie!    ||" << endl;
    cout << " ||                  ||" << endl;
    cout << " ======================" << endl;
    cout << "\n\n";
    cout << "Would you like to:" << endl;
    cout << "1. Play Again" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice (1/2): ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Invalid input. Please enter 1 or 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    bool playAgain = true;
    while (playAgain) {
        char board[SIZE][SIZE];
        initializeBoard(board);
        char currentPlayer = 'X';
        bool gameActive = true;

        while (gameActive) {
            printBoard(board);
            cout << "Current Turn: Player " << currentPlayer << endl;
            pair<int, int> move = getPlayerInput();
            int row = move.first;
            int col = move.second;

            if (updateBoard(row, col, currentPlayer, board)) {
                char winner = checkWinner(board);
                if (winner != ' ') {
                    printBoard(board);
                    cout << "Player " << winner << " wins!" << endl;
                    gameActive = false;
                } else if (isBoardFull(board)) {
                    int choice;
                    printBoard(board);
                    displayTieMessage(choice);
                    if (choice == 1) {
                        playAgain = true;
                    } else {
                        playAgain = false;
                    }
                    gameActive = false;
                } else {
                    switchTurn(currentPlayer);
                }
            } else {
                cout << "Invalid move, try again." << endl;
            }
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}