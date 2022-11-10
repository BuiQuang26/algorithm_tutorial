#include <bits/stdc++.h>
using namespace std;

int n, m; // chieu dai, rong cua mot ma tran
char a[1001][1001];
bool visited[1001][1001];

// 4 buoc di chuyen quanh cac dinh co canh lien ke
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void dfs(int i, int j)
{
    visited[i][j] = true;
    // duyet cac dinh ke
    for (int k = 0; k < 4; k++)
    {
        int _i = i + dx[k];
        int _j = j + dy[k];

        // check dinh nam trong bang
        if (_i >= 1 && _i <= n && _j >= 1 && _j <= m && a[_i][_j] == a[i][j] && !visited[_i][_j])
        {
            dfs(_i, _j);
        }
    }
}

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                ++cnt;
            }
        }

    cout << cnt;
}

int main()
{
    init();
    return 0;
}