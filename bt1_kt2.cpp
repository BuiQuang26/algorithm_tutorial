#include <bits/stdc++.h>
using namespace std;

struct Mobile
{
    string brand;
    int size;
    float price;
};

int n = 5;
Mobile mobiles[5] = {
    {"iphone 1", 5, 12},
    {"ss s6", 3, 8},
    {"iphone 8", 14, 3},
    {"ss s7", 4, 8},
    {"iphone 12", 2, 6}};

int getMobiles(Mobile mobi[], int n, int s)
{
    float L[n + 1][s + 1];

    // init cac gia tri ban dau
    for (int i = 0; i <= n; i++)
    {
        L[i][0] = 0;
    }
    for (int i = 0; i <= s; i++)
    {
        L[0][i] = 0;
    }

    // tinh cac kq tiep theo
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            L[i][j] = L[i - 1][j];
            if (mobi[i - 1].size <= j && L[i - 1][j - mobi[i - 1].size] + mobi[i - 1].price > L[i][j])
            {
                L[i][j] = L[i - 1][j - mobi[i - 1].size] + mobi[i - 1].price;
            }
        }
    }

    // show bang kq
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    // truy vet kq
    int dem = 0; // so sp lay ra phu hop
    float maxPrice = L[n][s];
    for (int i = n; i > 0; i--)
    {
        if (L[i][s] != L[i - 1][s])
        {
            cout << mobi[i - 1].brand << endl;
            s = s - mobi[i - 1].size;
            dem += 1;
        }
    }

    return dem;
}

int findMobileInPrice(Mobile mobi[], int l, int r, float minPrice, float maxPrice)
{
    if (l >= r)
    {
        if (mobi[r].price >= minPrice && mobi[r].price <= maxPrice)
        {
            return 1;
        }
        return 0;
    }
    int m = (l + r) / 2;
    return findMobileInPrice(mobi, l, m, minPrice, maxPrice) + findMobileInPrice(mobi, m + 1, r, minPrice, maxPrice);
}

int main()
{
    int s;
    cin >> s;

    int count = getMobiles(mobiles, n, s);
    cout << count << endl;
    cout << "------------" << endl;
    cout << findMobileInPrice(mobiles, 0, n - 1, 3, 6);
    return 0;
}