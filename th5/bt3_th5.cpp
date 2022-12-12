#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    int n = 15;
    double a[n] = {43, 59, 0, 61, 61, 76, 46, 89, -5, 77, 81, 76, 22, 88, -2};
    // srand(time(NULL));
    // for (int i = 0; i < n; i++)
    // {
    //     a[i] = rand() % 100 - 10;
    // }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // mang luu chi so max trong day con tang dan tai vi tri i
    int l[15];

    // day con tang dan tai tat cac vi tri khi co 1 phan tu
    for (int i = 0; i < n; i++)
    {
        l[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && l[i] < l[j] + 1)
                l[i] = l[j] + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << l[i] << " ";
    }

    int max = *max_element(l, l + n);

    cout << "\n"
         << *max_element(l, l + n) << endl;

    // truy vet cac phan tu cua day con tang dan dai nhat
    stack<double> s;
    for (int i = n; i >= 0; --i)
    {
        if (l[i] == max)
        {
            s.push(a[i]);
            --max;
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}