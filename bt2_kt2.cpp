#include <bits/stdc++.h>
using namespace std;

int n = 5;

int minLength(string d[], int l, int r)
{
    if (l >= r)
        return r;

    int m = (l + r) / 2;
    if (d[minLength(d, m + 1, r)].length() < d[minLength(d, l, m)].length())
    {
        return minLength(d, m + 1, r);
    }
    else
    {
        return minLength(d, l, m);
    }
}

int sumLength(string d[], int l, int r)
{
    if (l >= r)
        return d[r].length();
    int m = (l + r) / 2;
    return sumLength(d, l, m) + sumLength(d, m + 1, r);
}

// merge sort
void merge(string d[], int l, int m, int r)
{
    string b[r + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (d[i].length() < d[j].length())
        {
            b[k] = d[i];
            i++;
        }
        else
        {
            b[k] = d[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        b[k] = d[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        b[k] = d[j];
        j++;
        k++;
    }
    k = 0;
    while (r >= l)
    {
        d[l] = b[k];
        k++;
        l++;
    }
}

void sort(string d[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    sort(d, l, m);
    sort(d, m + 1, r);
    merge(d, l, m, r);
}

int find(string d[], int l, int r, string st)
{
    if (l >= r)
    {
        if (d[r] == st)
            return r;
        return -1;
    }
    int m = (l + r) / 2;
    if (find(d, l, m, st) != -1)
    {
        return find(d, l, m, st);
    }
    else
        return find(d, m + 1, r, st);
}

// Boyer Moore Horspoo
int char_in_string(char t, string p)
{
    for (int i = 0; i < p.length(); i++)
    {
        if (t == p[i])
            return i;
    }
    return -1;
}

bool findBoyerMooreHorspoo(string t, string p)
{
    int i = p.length();
    int v = p.length();

    while (i <= t.length())
    {
        int x = v - 1, j = i - 1;
        while (t[j] == p[x] && x > -1)
        {
            x--;
            j--;
        }
        if (x < 0)
            return true;
        else
        {
            x = char_in_string(t[j], p);
            if (x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }

    return false;
}

int findInList(string d[], int n, string st)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (findBoyerMooreHorspoo(d[i], st))
        {
            cout << d[i] << endl;
            dem++;
        }
    }

    return dem;
}
//---------------------------

int main()
{

    string d[n] = {"what your name", "how are you", "hello", "bye", "have a good day"};

    cout << d[minLength(d, 0, n - 1)] << endl;
    cout << sumLength(d, 0, n - 1) << endl;

    cout << "---------" << endl;
    cout << find(d, 0, n - 1, "hello") << endl;
    cout << "---------" << endl;

    sort(d, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << endl;
    }

    cout << "---------" << endl;
    cout << findInList(d, n, "day");

    return 0;
}