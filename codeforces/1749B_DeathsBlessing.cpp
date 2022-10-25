// https://codeforces.com/problemset/problem/1749/B
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int monsters;
        cin >> monsters;
        long long health[monsters];
        long long power[monsters];
        for (int i = 0; i < monsters; i++)
        {
            cin >> health[i];
        }

        for (int i = 0; i < monsters; i++)
        {
            cin >> power[i];
        }

        long long result = 0;
        long long max = 0;
        for (int i = 0; i < monsters; i++)
        {
            result = result + health[i];
            result = result + power[i];
            if (power[i] > max)
            {
                max = power[i];
            }
        }
        result = result - max;
        cout << result << endl;
    }
}