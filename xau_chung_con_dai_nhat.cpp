#include <bits/stdc++.h>
using namespace std;

// tim xau con chung dai nhat : quy hoach dong
int xau_chung_con_dai_nhat(string t, string p)
{
    int L[t.length() + 1][p.length() + 1];
    for (int i = 0; i <= t.length(); i++)
        L[i][0] = 0;
    for (int j = 0; j <= p.length(); j++)
        L[0][j] = 0;

    for (int i = 1; i <= t.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            if (t[i - 1] == p[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    for (int i = 1; i <= t.length(); i++)
    {
        for (int j = 1; j <= p.length(); j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    // truy vet
    for (int i = 0; i <= t.length(); i++)
    {
        if (L[i][p.length()] != L[i + 1][p.length()])
        {
            cout << t[i - 1];
        }
    }
    return L[t.length()][p.length()];
}

int main()
{
    int cnt = xau_chung_con_dai_nhat("xin chao", "em xin rat chao anh");
    return 0;
}