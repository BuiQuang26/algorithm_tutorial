#include <bits/stdc++.h>
using namespace std;
// 0 1 2 3 4 5 6
// 1 1 2 3 5 8 13

vector<long> a;

long long fibonaccy(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fibonaccy(n - 1) + fibonaccy(n - 2);
    }
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        a.push_back(fibonaccy(i));
    }

    for (long i : a)
    {
        cout << i << " ";
    }
    return 0;
}
