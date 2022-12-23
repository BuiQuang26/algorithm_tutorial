#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    int dob;
    string address;
};

void show(Student students[], int n)
{
    cout << "-- list student --" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << students[i].name << endl;
    }
    cout << endl;
}

int findStudent(Student students[], int l, int r, string name)
{

    if (l >= r)
    {
        if (students[r].name == name)
            return r;
        return -1;
    }
    int m = (l + r) / 2;
    int p = findStudent(students, l, m, name);
    if (p > -1)
        return p;
    else
        return findStudent(students, m + 1, r, name);
}

int main()
{
    int n = 6;
    Student students[n] = {
        {"Bui Quang", 2000, "Ha Noi"},
        {"Van Lam", 2001, "Ha Noi"},
        {"Quang Hai", 1999, "Ha Noi"},
        {"Van Quyet", 2002, "Ha Noi"},
        {"Quang Hai", 1999, "Ha Noi"},
        {"Tuan Anh", 1998, "Ha Noi"}};

    show(students, n);
    cout << findStudent(students, 0, n - 1, "Quang Hai");
    return 0;
}