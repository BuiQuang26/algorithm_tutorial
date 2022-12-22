#include <bits/stdc++.h>
using namespace std;

int count_number_le(int a[], int vt)
{
    if (vt < 0)
    {
        return 0;
    }
    if (a[vt] % 2 == 0)
        return 1 + count_number_le(a, vt - 1);
    return count_number_le(a, vt - 1);
}

int sum_so_le(int a[], int vt)
{
    if (vt < 0)
    {
        return 0;
    }
    if (a[vt] % 2 == 0)
        return a[vt] + sum_so_le(a, vt - 1);
    return sum_so_le(a, vt - 1);
}

void showNumberReverse(int a)
{
    if (a <= 0)
        return;
    cout << a % 10;
    showNumberReverse(a / 10);
}

int main()
{
    int n = 20;
    int a[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000 + 1000;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // show list a sao cho cac so hien thi nguoc
    cout << "> show list a sao cho cac so hien thi nguoc ---" << endl;
    for (int i = 0; i < n; i++)
    {
        showNumberReverse(a[i]);
        cout << " ";
    }
    cout << endl;

    cout << "> trung binh cong cac so le trong mang ---" << endl;
    double count = count_number_le(a, n - 1);
    double sum = sum_so_le(a, n - 1);
    if (count > 0)
    {
        double tb = sum / count;
        cout << tb;
    }

    return 0;
}