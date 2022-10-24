// https://codeforces.com/problemset/problem/1754/A
#include <iostream>
using namespace std;

bool solve(int exchanges, char messages[100])
{
    int q_cnt = 0;
    for (int i = 0; i < exchanges; i++)
    {
        char letter = messages[i];
        q_cnt = letter == 'A' ? q_cnt - 1 : q_cnt + 1;
        if (q_cnt < 0)
            q_cnt++;
    }
    if (q_cnt <= 0)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    char messages[100];
    while (n--)
    {
        int exchanges;
        cin >> exchanges;
        cin >> messages;
        bool result = solve(exchanges, messages);
        if (result)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}