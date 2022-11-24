#include <bits/stdc++.h>
using namespace std;

int ucln(int a, int b)
{
    if (b == 0)
        return a;

    return ucln(b, a % b);
}

int main()
{
    cout << ucln(15, 20);
    return 0;
}