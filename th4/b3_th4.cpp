#include <bits/stdc++.h>
using namespace std;

void show(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

double max(double a[], int l, int r)
{
    if (l >= r)
        return a[l];

    int mid = (l + r) / 2;
    double max1 = max(a, l, mid);
    double max2 = max(a, mid + 1, r);

    if (max1 > max2)
        return max1;
    else
        return max2;
}

int main()
{
    double a[15];
    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        a[i] = rand() % 1000;
    }

    show(a, 15);
    cout << max(a, 0, 14);

    return 0;
}