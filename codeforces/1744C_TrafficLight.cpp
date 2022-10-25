// https://codeforces.com/problemset/problem/1744/C
#include <iostream>
using namespace std;

int search(int pos[], int size, int trgt, int lights)
{
    for (int i = 0; i < size; i++)
    {
        if (pos[i] > trgt)
        {
            return (pos[i] - trgt);
        }
    }
    return (lights - (trgt - pos[0]));
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char clr;
        int size;
        cin >> size >> clr;
        string clrs;
        cin >> clrs;
        if (clr == 'g')
        {
            cout << 0 << endl;
            continue;
        }
        int greens[size];
        int greens_s = 0;
        int chosen[size];
        int chosen_s = 0;
        for (int i = 0; i < size; i++)
        {
            if (clrs[i] == clr)
            {
                chosen[chosen_s] = i;
                chosen_s++;
            }
            if (clrs[i] == 'g')
            {
                greens[greens_s] = i;
                greens_s++;
            }
        }
        int max = 0;
        for (int i = 0; i < chosen_s; i++)
        {
            int time = search(greens, greens_s, chosen[i], size);
            if (time > max)
            {
                max = time;
            }
        }
        cout << max << endl;
    }
}