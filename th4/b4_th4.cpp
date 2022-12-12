#include <bits/stdc++.h>
using namespace std;

double calculator(double a, int l, int r)
{
    if (l > r)
        return 1;
    if (l == r)
        return a;
    int m = (l + r) / 2;
    return calculator(a, l, m) * calculator(a, m + 1, r);
}

int main()
{
    double a;
    int n;

    cin >> a >> n;
    cout << calculator(a, 0, n - 1);
    return 0;
}