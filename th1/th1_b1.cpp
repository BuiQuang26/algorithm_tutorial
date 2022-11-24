#include <bits/stdc++.h>
using namespace std;

int n, a[100];

void show()
{
    for (int i = n; i > 0; --i)
    {
        cout << a[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int i = 0; i < 2; i++)
    {
        a[k] = i;
        if (k > 0)
        {
            Try(k - 1);
        }
    }

    if (k == 0)
    {
        show();
    }
}

int main()
{
    cin >> n;
    Try(n);
    return 0;
}