#include <bits/stdc++.h>
using namespace std;

int countMoney(int a[], int n, int target)
{
    int i = 0, cnt = 0;
    while (target > 0 && i < n)
    {
        cnt += target / a[i];
        target = target % a[i];
        i++;
    }
    return cnt;
}

int main()
{
    int n = 8;
    int a[n] = {500, 200, 100, 50, 20, 10, 5, 1};
    int cnt = countMoney(a, n, 1000);
    cout << cnt;
    return 0;
}