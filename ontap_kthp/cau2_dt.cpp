#include <bits/stdc++.h>
using namespace std;

struct PhieuThu
{
    int id;
    long moneyTotal;
};

void showPhieuThu(PhieuThu phieuthus[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " > " << phieuthus[i].id << " : " << phieuthus[i].moneyTotal << endl;
    }
    cout << endl;
}

void sort(PhieuThu phieuthus[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
        {
            if (phieuthus[i].moneyTotal < phieuthus[j].moneyTotal)
            {
                swap(phieuthus[i], phieuthus[j]);
            }
        }
}

int getPhieuThu(PhieuThu phieuthus[], int n, long target)
{
    int dem = 0;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        if (phieuthus[i].moneyTotal < target)
        {
            dem += target / phieuthus[i].moneyTotal;
            cout << phieuthus[i].moneyTotal << " : " << target / phieuthus[i].moneyTotal << endl;
            target = target % phieuthus[i].moneyTotal;
        }
    }

    if (target > 0)
        dem++;

    return dem;
}

int findVtChenPhieuThua(PhieuThu phieuThus[], int l, int r, PhieuThu newPhieuThu)
{
    if (l >= r)
    {
        if (phieuThus[r].moneyTotal > newPhieuThu.moneyTotal)
            return r + 1;
        return r;
    }
    int m = (l + r) / 2;
    if (phieuThus[m].moneyTotal < newPhieuThu.moneyTotal)
        return findVtChenPhieuThua(phieuThus, l, m, newPhieuThu);
    return findVtChenPhieuThua(phieuThus, m + 1, r, newPhieuThu);
}

void chenPhieuThu(PhieuThu phieuThus[], PhieuThu newPhieuThus[], int n, int vt, PhieuThu phieuthu)
{
    for (int i = 0; i <= n; i++)
    {
        if (i > vt)
            newPhieuThus[i] = phieuThus[i - 1];
        else if (i < vt)
        {
            newPhieuThus[i] = phieuThus[i];
        }
    }
    newPhieuThus[vt] = phieuthu;
}

int main()
{
    int n = 10;
    srand(time(NULL));
    PhieuThu phieuThus[n];
    for (int i = 0; i < n; i++)
        phieuThus[i] = {i, rand() % 100 * 100000};

    showPhieuThu(phieuThus, n);
    sort(phieuThus, n);
    showPhieuThu(phieuThus, n);
    // chen phieu thu moi
    PhieuThu newPhieuthu = {9999, 2327487};

    int vt_chen = findVtChenPhieuThua(phieuThus, 0, n - 1, newPhieuthu);
    PhieuThu newPhieuThus[n + 1];
    chenPhieuThu(phieuThus, newPhieuThus, n, vt_chen, newPhieuthu);
    showPhieuThu(newPhieuThus, n + 1);

    cout << "tong so phieu thu : " << endl;
    cout << getPhieuThu(newPhieuThus, n + 1, 150000000);

    return 0;
}