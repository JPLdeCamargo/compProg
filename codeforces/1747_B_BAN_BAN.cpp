#include <bits/stdc++.h>
using namespace std;
void solve(int size)
{

    int start = 1;
    int end = size;
    int result = 0;
    int l[size];
    int r[size];
    while (start < end)
    {
        l[result] = start;
        r[result] = end;
        result++;
        start += 3;
        end -= 3;
    }
    cout << result << endl;
    for (int i = 0; i < result; i++)
    {
        cout << l[i] << " " << r[i] << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size;
        cin >> size;
        solve(size * 3);
    }
}