// https://codeforces.com/problemset/problem/1721/B
#include <bits/stdc++.h>
using namespace std;
int distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int solve(int n, int m, int sx, int sy, int d)
{
    if (distance(n, m, sx, sy) <= d)
    {
        return -1;
    }
    int distant_wall = ((sx - 1) <= abs(sx - n)) ? n : 1;
    if (distance(sx, sy, distant_wall, sy) <= d)
    {
        return -1;
    }
    distant_wall = ((sy - 1) <= abs(sy - m)) ? m : 1;
    if (distance(sx, sy, sx, distant_wall) <= d)
    {
        return -1;
    }

    int closer_wally = ((sy - 1) <= abs(sy - m)) ? 1 : m;
    int closer_wallx = ((sx - 1) <= abs(sx - n)) ? 1 : n;
    if (distance(sx, sy, closer_wallx, sy) <= d && distance(sx, sy, sx, closer_wally) <= d)
    {
        if (closer_wallx == 1 && closer_wally == 1)
        {
            return -1;
        }
        if (closer_wallx == n && closer_wally == m)
        {
            return -1;
        }
    }

    return distance(1, 1, n, m);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        cout << solve(n, m, sx, sy, d) << endl;
    }
    return 0;
}