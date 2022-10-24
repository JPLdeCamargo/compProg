// https://codeforces.com/problemset/problem/1754/B
// Consegui
#include <iostream>
using namespace std;

int main()
{
    int n;
    int results[1000];
    cin >> n;
    while (n--)
    {
        int range;
        cin >> range;
        int cnt = 0;
        int max = range / 2;
        int odd = range % 2;
        for (int i = 1; i <= max; i++)
        {
            int lesser = i;
            int greater = i + max;
            results[cnt] = greater;
            results[cnt + 1] = lesser;
            cnt = cnt + 2;
        }

        if (odd)
        {
            results[range - 1] = range;
        }

        for (int i = 0; i < range; i++)
        {
            cout << results[i] << " ";
        }
        cout << endl;
    }
}