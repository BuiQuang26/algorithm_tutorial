#include <bits/stdc++.h>
using namespace std;

int ucln(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

int main()
{
    cout << ucln(0, 5);
    return 0;
}