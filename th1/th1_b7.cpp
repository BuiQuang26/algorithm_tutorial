#include <bits/stdc++.h>
using namespace std;

long a[100];

long f(int k)
{
    if (k < 2)
        return 1;

    if (a[k] > 1)
        return a[k];

    a[k] = f(k - 1) + f(k - 2);

    return a[k];
}

int main()
{
    cout << f(1) << " " << f(2) << " " << f(3) << " " << f(4) << " " << f(5) << " " << f(6);

    return 0;
}