#include <bits/stdc++.h>
using namespace std;

int min_k(int a[], int l, int r, int k)
{

    if (l >= r)
    {
        if (a[r] > k)
            return r;
        return -1;
    }

    int m = (l + r) / 2;
    int vtl = min_k(a, l, m, k);
    int vtr = min_k(a, m + 1, r, k);
    if (vtl > -1 && vtr > -1)
    {
        if (a[vtl] > a[vtr])
            return vtr;
        return vtl;
    }
    else if (vtl > -1)
    {
        return vtl;
    }
    else
        return vtr;
}

int main()
{
    int n = 15;
    int k, a[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
    }

    k = 20;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << a[min_k(a, 0, n - 1, k)];

    return 0;
}
