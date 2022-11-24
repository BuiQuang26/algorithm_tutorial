#include <bits/stdc++.h>
using namespace std;

// tong cac so duong trong mang
double sum(double a[], int l, int r)
{
    if (l >= r)
    {
        if (a[r] > 0)
            return a[r];
        else
            return 0;
    }

    int mid = (l + r) / 2;
    return sum(a, l, mid) + sum(a, mid + 1, r);
}

void show(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 20;
    double a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 - 50;
    }

    show(a, n);

    cout << sum(a, 0, n - 1);

    return 0;
}