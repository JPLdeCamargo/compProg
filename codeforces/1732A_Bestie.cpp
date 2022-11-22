// https://codeforces.com/problemset/problem/1732/A
#include <iostream>
#include <algorithm>
using namespace std;
int get_min(int nums[], int size)
{
    int min = nums[0];
    for (int i = 1; i < size; i++)
    {
        if (nums[i] < min)
            min = nums[i];
    }
    return min;
}
int get_gcd(int a, int b)
{
    if (a == 0)
        return b;
    return get_gcd(b % a, a);
}
int get_gcd_array(int nums[], int size)
{
    int result = nums[0];
    for (int i = 1; i < size; i++)
    {
        result = get_gcd(nums[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

int solve(int nums[], int size)
{
    int gcd = get_gcd_array(nums, size);

    if (gcd == 1)
        return 0;

    if (get_gcd(gcd, size) == 1)
    {
        return 1;
    }
    if (get_gcd(gcd, size - 1) == 1)
    {
        return 2;
    }
    if (get_gcd((get_gcd(gcd, size)), size - 1) == 1)
        return 3;
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
            cin >> nums[i];
        }
        cout << solve(nums, size) << endl;
    }
}