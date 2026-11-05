
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int N, int row, int col)
{
    // Check same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int N, int row)
{
    // All queens are placed
    if (row == N)
        return true;

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, N, row, col))
        {
            board[row][col] = 1;

            if (solveNQueens(board, N, row + 1))
                return true;

            // Backtracking
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int N, row, col;

    cout << "Enter board size: ";
    cin >> N;

    if (N <= 0)
    {
        cout << "Invalid board size!";
        return 0;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));

    cout << "Enter first queen position (row and column): ";
    cin >> row >> col;

    if (row < 0 || row >= N || col < 0 || col >= N)
    {
        cout << "Invalid position!";
        return 0;
    }

    board[row][col] = 1;

    if (solveNQueens(board, N, row + 1))
    {
        cout << "\nSolution:\n";

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists!";
    }

    return 0;
}
