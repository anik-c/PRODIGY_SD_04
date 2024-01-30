#include <iostream>
#include <vector>
#include <conio.h>
#define SKYBLUE "\033[1;36m"
#define RED "\033[31m"
#define GREEN "\033[32m"
using namespace std;
bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
        if (board[i][col] == val)
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &board)
{
    int n = board.size();
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        bool soultionPossible = solve(board);
                        if (soultionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    cout << SKYBLUE << "*****************SUDOKU SOLVER*****************" << endl;
    cout << SKYBLUE << "Enter your elements: " << endl;
    vector<vector<int>> board(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << "*****************SOLVED SUDOKU*****************" << endl;
    if (solve(board))
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                cout << GREEN << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << RED << "No solution exists." << endl;
    }
    getch();
    return 0;
}