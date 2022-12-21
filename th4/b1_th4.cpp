#include <bits/stdc++.h>
using namespace std;

struct HOCSINH
{
    string first_name;
    string last_name;
    int year;
    string address;
};

void show(HOCSINH hs[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << hs[i].last_name << " " << hs[i].first_name << " " << hs[i].year << " " << hs[i].address << endl;
    }
}

// sort
void sort(HOCSINH hs[], int l, int r)
{
    if (l > r)
        return;
    HOCSINH p = hs[r];
    int j = l;
    for (int i = l; i < r; i++)
    {
        if (hs[i].first_name < p.first_name)
        {
            swap(hs[i], hs[j]);
            j++;
        }
    }
    swap(hs[r], hs[j]);
    sort(hs, l, j - 1);
    sort(hs, l + 1, r);
}

// search
int search(HOCSINH hs[], int l, int r, string first_name)
{
    if (l > r)
        return -1;

    int mid = (l + r) / 2;
    if (hs[mid].first_name == first_name)
        return mid;
    else if (hs[mid].first_name > first_name)
        return search(hs, l, mid - 1, first_name);
    else
        return search(hs, mid + 1, r, first_name);
}

int main()
{
    int n;
    cin >> n;
    HOCSINH hocsinhs[n];
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        cout << "Nhap thong tin hoc sinh " << i + 1 << endl;
        cin >> hocsinhs[i].last_name;
        cin >> hocsinhs[i].first_name;
        cin >> hocsinhs[i].year;
        cin >> hocsinhs[i].address;
    }

    show(hocsinhs, n);
    cout << endl;
    sort(hocsinhs, 0, n - 1);
    show(hocsinhs, n);
    string name;
    cout << "Tim kiem : ";
    cin >> name;

    int i = search(hocsinhs, 0, n - 1, name);
    cout << " vi tri = " << i << endl;

    if (i > -1)
        cout << hocsinhs[i].last_name << " " << hocsinhs[i].first_name << " " << hocsinhs[i].year << " " << hocsinhs[i].address << endl;
}
