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

int min_de_qui(int a[], int vt, int k)
{
    if (vt < 0)
    {
        return -1;
    }

    if (a[vt] <= k)
        return min_de_qui(a, vt - 1, k);
    else
    {
        int i = min_de_qui(a, vt - 1, k);
        if (i < 0 || a[i] > a[vt])
            return vt;
        else
            return i;
    }
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

    int i = min_de_qui(a, n - 1, k);
    if (i > -1)
        cout << a[i];

    return 0;
}
