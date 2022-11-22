// https://codeforces.com/problemset/problem/1725/B
#include <bits/stdc++.h>
using namespace std;

int solve(int p[], int n, int d)
{
    sort(p, p + n);
    int l_index = n - 1;
    int s_index = 0;
    int result = 0;
    while (true)
    {
        int needed = (d / p[l_index]);
        if (p[l_index] * (1 + needed) <= d)
            needed++;
        s_index += needed;
        if (s_index > l_index)
        {
            break;
        }
        result++;
        l_index--;
    }
    return result;
}

int main()
{
    int n, d;
    cin >> n >> d;
    int p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << solve(p, n, d) << endl;
}
