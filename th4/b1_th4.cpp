
int main()
{
    cout << findStudent(studentList, 0, n - 1, "B");
    showStudent(studentList, n);
    mergeSort(studentList, 0, n - 1);
    showStudent(studentList, n);
    return 0;
}