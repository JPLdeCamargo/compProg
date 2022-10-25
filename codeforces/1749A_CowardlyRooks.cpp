// https://codeforces.com/problemset/problem/1749/A
#include <iostream>
using namespace std;
string solve(bool columns[], bool rows[], int rooks, int pos[][2], int size)
{
    for (int i = 0; i < rooks; i++)
    {
        int row = pos[i][0];
        int column = pos[i][1];
        if (row - 1 >= 0)
        {
            if (rows[row - 1] == false)
            {
                return "YES";
            }
        }
        if (row + 1 < size)
        {
            if (rows[row + 1] == false)
            {
                return "YES";
            }
        }
        if (column - 1 >= 0)
        {
            if (columns[column - 1] == false)
            {
                return "YES";
            }
        }
        if (column + 1 < size)
        {
            if (columns[column + 1] == false)
            {
                return "YES";
            }
        }
    }
    return "NO";
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size, rooks;
        cin >> size >> rooks;
        bool columns[size];
        bool rows[size];
        for (int i = 0; i < size; i++)
        {
            columns[i] = false;
            rows[i] = false;
        }
        int pos[rooks][2];
        for (int i = 0; i < rooks; i++)
        {
            int row, column;
            cin >> row >> column;
            row--;
            column--;
            columns[column] = true;
            rows[row] = true;
            pos[i][0] = row;
            pos[i][1] = column;
        }
        string result = solve(columns, rows, rooks, pos, size);
        cout << result << endl;
    }
    return 0;
}