#include <bits/stdc++.h>
using namespace std;

int Try(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    if (a - b == 0)
        return a;

    else if (a > b)
    {
        Try(a - b, b);
    }
    else
    {
        Try(a, b - a);
    }

    return 0;
}

int ucln2(int a, int b)
{

    if (a == 0 || b == 0)
        return 0;

    while (a - b != 0)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ucln = ucln2(a, b);
    cout << ucln;
    return 0;
}