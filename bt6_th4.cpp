#include <bits/stdc++.h>
using namespace std;

void show(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// tim so chan nho nhat trong mang
//  ham return vi tri so do trong mang
// ket qua = -1. mang ko co phan tu chan
int min(int a[], int l, int r)
{
    if (l >= r)
    {
        if (a[r] != 0 && a[r] % 2 == 0)
            return a[r];

        return -1;
    }
    else
    {
        int mid = (l + r) / 2;
        int min1 = min(a, l, mid);
        int min2 = min(a, mid + 1, r);

        if (min1 != 0 && min2 != 0 && min1 % 2 == 0 && min2 % 2 == 0)
        {
            if (min1 > min2)
                return min2;
            else
                return min1;
        }
        else if (min1 != 0 && min1 % 2 == 0)
        {
            return min1;
        }
        else if (min2 != 0 && min2 % 2 == 0)
        {
            return min2;
        }
        else
            return -1;
    }
}

int main()
{

    int n = 15;
    int a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 - 10;
    }

    show(a, n);

    cout << min(a, 0, n - 1);

    return 0;
}