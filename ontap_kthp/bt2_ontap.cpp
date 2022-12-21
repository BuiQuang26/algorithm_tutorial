#include <bits/stdc++.h>
using namespace std;

// khoi tao kieu du lieu LOPHOC
struct LopHoc
{
    string maLop;
    int studentTotal;
    int girlStudent;
};

void showLopHoc(LopHoc lopHocs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "> " << lopHocs[i].maLop << ": " << lopHocs[i].studentTotal << ", " << lopHocs[i].girlStudent << endl;
    }
}

void sort(LopHoc lophocs[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
        {
            if (lophocs[i].studentTotal < lophocs[j].studentTotal)
            {
                swap(lophocs[i], lophocs[j]);
            }
        }
}

// tham lam
int getLopHoc(LopHoc lophocs[], int n, int k)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (lophocs[i].studentTotal <= k)
        {
            dem = dem + (k / lophocs[i].studentTotal);
            cout << dem << ", " << lophocs[i].maLop << endl;
            k = k % lophocs[i].studentTotal;
        }
    }
    if (k > 0)
        dem++;
    return dem;
}

// quy hoach dong
void quyHoachDong(LopHoc lophocs[], int n, int p)
{
    int L[n + 1][p + 1];
    for (int i = 0; i <= n; i++)
    {
        L[i][0] = 0;
    }
    for (int i = 0; i <= p; i++)
    {
        L[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            L[i][j] = L[i - 1][j];
            if (lophocs[i - 1].studentTotal <= j && L[i - 1][j - lophocs[i - 1].studentTotal] + lophocs[i - 1].girlStudent > L[i - 1][j])
            {
                int a = L[i - 1][j - lophocs[i - 1].studentTotal];
                int b = lophocs[i - 1].girlStudent;
                L[i][j] = a + b;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= p; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    // truy vet
    for (int i = n; i > 0; --i)
    {
        if (L[i][p] != L[i - 1][p])
        {
            printf("%s \n", lophocs[i - 1].maLop.c_str());
            p = p - lophocs[i - 1].studentTotal;
        }
    }
}

// xu ly xau
int chat_in_string(string s, char c)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
            return i;
    }
    return -1;
}

// check s co phai la chuoi con cua p khong?
bool string_in_string(string t, string p)
{
}

int main()
{
    int n = 10;
    LopHoc lopHocs[10] = {
        {"it1", 7, 3},
        {"it2", 6, 5},
        {"it3", 6, 3},
        {"it4", 8, 3},
        {"it5", 4, 2},
        {"it6", 6, 6},
        {"it7", 6, 5},
        {"it8", 5, 4},
        {"it9", 7, 5},
        {"it10", 8, 6},
    };
    sort(lopHocs, n);
    showLopHoc(lopHocs, n);

    int k, p;
    cout << "nhap k = ";
    cin >> k;
    cout << getLopHoc(lopHocs, n, k) << endl;
    cout << "nhap p = ";
    cin >> p;
    quyHoachDong(lopHocs, n, p);

    return 0;
}