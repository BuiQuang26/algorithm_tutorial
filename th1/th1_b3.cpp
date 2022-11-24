#include <bits/stdc++.h>
using namespace std;

int k, n, a[100], last = 0;

void ktao()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
    }
}

// n = 5, k = 3
// 123 124 125 134 135 234 235 345

void sinh()
{
    int i = k;
    // check max
    while (i >= 0 && a[i] == n - k + i)
    {
        --i;
    }

    if (i == 0)
        last = 1;
    else
    {
        a[i] += 1;
        for (int j = i + 1; j <= k; j++)
        {
            a[j] = a[j - 1] + 1;
        }
    }
}

int main()
{
    cin >> n >> k;
    ktao();
    while (last != 1)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }

    return 0;
}