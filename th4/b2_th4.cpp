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

// tron 2 mang da sx: mang1(a[], l -> m), mang2(a[], m + 1 -> r)
void merge(double a[], int l, int mid, int r)
{
    double b[r + 1];
    int x = l, y = mid + 1, k = 0;
    while (x <= mid && y <= r)
    {
        if (a[x] < a[y])
        {
            b[k] = a[x];
            k++;
            x++;
        }
        else
        {
            b[k] = a[y];
            k++;
            y++;
        }
    }
    while (x <= mid)
    {
        b[k] = a[x];
        k++;
        x++;
    }
    while (y <= r)
    {
        b[k] = a[y];
        y++;
        k++;
    }
    k = 0;
    while (l <= r)
    {
        a[l] = b[k];
        k++;
        l++;
    }
}

void mergeSort(double a[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main()
{
    int n = 15;
    double a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 - 50;
    }

    show(a, n);

    mergeSort(a, 0, n - 1);

    show(a, n);

    return 0;
}