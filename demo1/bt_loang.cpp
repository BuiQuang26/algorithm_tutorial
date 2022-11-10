#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[12][12];

    srand(time(NULL));

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            a[i][j] = rand() % (5 + 1);
        }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "------------------------" << endl;

        return 0;
}
