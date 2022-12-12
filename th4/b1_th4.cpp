#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string firtName;
    string lastName;
    int dob;
    string addr;
};

int n = 6;
Student studentList[6] = {
    {"A", "Bui", 2000, "Ha noi"},
    {"D", "Thuy", 2000, "Ha noi"},
    {"M", "Trong", 2000, "Ha noi"},
    {"C", "Nguyen", 2000, "Ha noi"},
    {"K", "Xuan", 2000, "Ha noi"},
    {"B", "Van", 2000, "Ha noi"}};

void showStudent(Student students[], int n)
{
    cout << endl
         << "------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << students[i].lastName << " " << students[i].firtName << endl;
    }
}

// merge sort
void merge(Student students[], int l, int m, int r)
{
    Student tg[r + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (students[i].firtName < students[j].firtName)
        {
            tg[k] = students[i];
            i++;
        }
        else
        {
            tg[k] = students[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        tg[k] = students[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        tg[k] = students[j];
        j++;
        k++;
    }

    k = 0;
    while (l <= r)
    {
        students[l] = tg[k];
        l++;
        k++;
    }
}

void mergeSort(Student students[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(students, left, mid);
    mergeSort(students, mid + 1, right);
    merge(students, left, mid, right);
}

// find student
int findStudent(Student students[], int l, int r, string studentName)
{
    if (l > r)
        return -1;
    int m = (l + r) / 2;
    if (students[m].firtName == studentName)
        return m;
    if (findStudent(students, l, m - 1, studentName) != -1)
        return findStudent(students, l, m - 1, studentName);
    else
        return findStudent(students, m + 1, r, studentName);
}

int main()
{
    cout << findStudent(studentList, 0, n - 1, "B");
    showStudent(studentList, n);
    mergeSort(studentList, 0, n - 1);
    showStudent(studentList, n);
    return 0;
}