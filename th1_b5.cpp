#include <bits/stdc++.h>
using namespace std;

int n, a[100], last = 0;

void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
}

// 5
// 12345 12354 12435 12453 12534 12543

void sinh()
{
    int i = n - 1;
    while (i >= 0 && a[i] > a[i + 1])
    {
        --i;
    }

    if (i == 0)
        last = 1;
    else
    {
        int j = n;
        while (a[j] < a[i])
            --j;

        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
}

int main()
{
    cin >> n;
    ktao();
    while (last != 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }

    return 0;
}