// https://codeforces.com/problemset/problem/1746/B
#include <bits/stdc++.h>
using namespace std;
void print(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void get_1(int &a, int nums[], int size)
{
    for (a; a < size; a++)
    {
        if (nums[a] == 1)
        {
            nums[a] = 0;
            return;
        }
    }
}

void get_0(int &b, int nums[], int size, int &a)
{
    for (b; b >= a; b--)
    {
        if (nums[b] == 0)
        {
            nums[b] = 1;
            return;
        }
    }
}

int solve(int nums[], int size)
{

    int result = -1;
    int a = 0;
    int b = size - 1;
    if (a == b)
        return 0;
    while (b > a)
    {
        result++;
        get_1(a, nums, size);
        if (a == size)
            return 0;
        get_0(b, nums, size, a);
        if (b == -1)
            return 0;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size;
        cin >> size;
        int nums[size];
        for (int i = 0; i < size; i++)
        {
            int num;
            cin >> num;
            nums[i] = num;
        }

        int result = solve(nums, size);
        cout << result << endl;
    }
}