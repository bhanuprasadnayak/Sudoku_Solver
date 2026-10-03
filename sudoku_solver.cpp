#include <iostream>
#include <string>

using namespace std;

class Sudoku {

private:
    int board[9][9];
    int size;

public:

    Sudoku(int n) {
        size = n;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = 0;
            }
        }
    }

    void inputBoard() {

        cout << "\nEnter the Sudoku:\n";
        cout << "(Use 0 for empty cells)\n\n";

        string row;

        for (int i = 0; i < size; i++) {

            cin >> row;

            while (row.length() != size) {
                cout << "Invalid row. Enter exactly "
                     << size << " digits: ";

                cin >> row;
            }

            for (int j = 0; j < size; j++) {
                board[i][j] = row[j] - '0';
            }
        }
    }

    void printBoard() {

        cout << "\n";

        if (size == 9) {

            cout << "-------------------------\n";

            for (int i = 0; i < 9; i++) {

                cout << "| ";

                for (int j = 0; j < 9; j++) {

                    if (board[i][j] == 0)
                        cout << ". ";
                    else
                        cout << board[i][j] << " ";

                    if ((j + 1) % 3 == 0)
                        cout << "| ";
                }

                cout << "\n";

                if ((i + 1) % 3 == 0)
                    cout << "-------------------------\n";
            }
        }

        else {

            cout << "---------------------\n";

            for (int i = 0; i < 6; i++) {

                cout << "| ";

                for (int j = 0; j < 6; j++) {

                    if (board[i][j] == 0)
                        cout << ". ";
                    else
                        cout << board[i][j] << " ";

                    if ((j + 1) % 3 == 0)
                        cout << "| ";
                }

                cout << "\n";

                if ((i + 1) % 2 == 0)
                    cout << "---------------------\n";
            }
        }
    }

    bool isSafe(int row, int col, int num) {

        // Check row
        for (int j = 0; j < size; j++) {

            if (board[row][j] == num)
                return false;
        }

        // Check column
        for (int i = 0; i < size; i++) {

            if (board[i][col] == num)
                return false;
        }

        // 3x3 box for 9x9
        if (size == 9) {

            int startRow = row - row % 3;
            int startCol = col - col % 3;

            for (int i = startRow; i < startRow + 3; i++) {

                for (int j = startCol; j < startCol + 3; j++) {

                    if (board[i][j] == num)
                        return false;
                }
            }
        }

        // 2x3 box for 6x6
        else {

            int startRow = row - row % 2;
            int startCol = col - col % 3;

            for (int i = startRow; i < startRow + 2; i++) {

                for (int j = startCol; j < startCol + 3; j++) {

                    if (board[i][j] == num)
                        return false;
                }
            }
        }

        return true;
    }

    bool solve() {

        for (int row = 0; row < size; row++) {

            for (int col = 0; col < size; col++) {

                if (board[row][col] == 0) {

                    for (int num = 1; num <= size; num++) {

                        if (isSafe(row, col, num)) {

                            board[row][col] = num;

                            if (solve())
                                return true;

                            // Backtrack
                            board[row][col] = 0;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
};


int main() {

    int choice;

    cout << "=========================\n";
    cout << "      SUDOKU SOLVER\n";
    cout << "=========================\n\n";

    cout << "1. 6 x 6 Sudoku\n";
    cout << "2. 9 x 9 Sudoku\n\n";

    cout << "Enter your choice: ";
    cin >> choice;

    Sudoku* game = nullptr;

    switch (choice) {

        case 1:
            game = new Sudoku(6);
            break;

        case 2:
            game = new Sudoku(9);
            break;

        default:
            cout << "Invalid choice!\n";
            return 0;
    }

    game->inputBoard();

    cout << "\nOriginal Sudoku:";
    game->printBoard();

    if (game->solve()) {

        cout << "\nSolved Sudoku:";
        game->printBoard();

    }
    else {

        cout << "\nNo solution exists for this Sudoku.\n";
    }

    delete game;

    return 0;
}