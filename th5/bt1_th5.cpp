#include <bits/stdc++.h>
using namespace std;

void show(int w[], int v[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << w[i] << " " << v[i] << endl;
    }
}

int maxValue(int w[], int v[], int n, int m)
{
    int maxV[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        maxV[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        maxV[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            maxV[i][j] = maxV[i - 1][j];
            if (w[i] <= j && maxV[i - 1][j - w[i]] + v[i] > maxV[i - 1][j])
            {
                maxV[i][j] = maxV[i - 1][j - w[i]] + v[i];
            }
        }
    }

    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int l = 1; l <= m; l++)
        {
            cout << maxV[i][l] << " ";
        }
        cout << endl;
    }

    /**
     *  Truy vết
     * Trường hợp 1: Trong bảng phương án F[n,m] chính là giá trị lớn nhất thu được khi chọn trong cả
     * vật với giới hạn trọng lượng là M. Nếu f[n,M]=f[n-1,M] thì tức là không chọn vật thứ n, ta truy
     * về f[n-1,M]. Còn nếu f[n,M]≠f[n-1,M] thì ta thông báo rằng phép chọn tối ưu có chọn vật thứ n và
     * truy về f[n-1,M-Wn].
     *
     * Trường hợp 2: Trong bảng phương án F[n,m] chính là giá trị lớn nhất thu được khi chọn trong cả n vật
     * với giới hạn trọng lượng là M. Nếu f[n,M]=f[n-1,M] thì tức là không chọn vật thứ n, ta truy về f[n-1,M].
     * Còn nếu f[n,M]≠f[n-1,M] thì ta thông báo rằng phép chọn tối ưu có chọn vật thứ n và truy về f[n,M-Wn].
     */
    int total = 0;
    int j = m;
    cout << "----------------" << endl;
    for (int i = n; i > 0; --i)
    {
        if (maxV[i][j] != maxV[i - 1][j])
        {
            cout << i << " : " << w[i] << " " << v[i] << endl;
            j = j - w[i];
            total++;
        }
    }
    cout << "total : " << total << endl;

    return maxV[n][m];
}

int main()
{
    srand(time(NULL));
    int n = 5, m;
    int w[n + 1], v[n + 1];

    for (int i = 1; i <= n; i++)
    {
        w[i] = rand() % 10 + 1;
        v[i] = rand() % 10 + 1;
    }

    show(w, v, n);
    cin >> m;

    int max = maxValue(w, v, n, m);
    cout << "max value : " << max << endl;

    return 0;
}