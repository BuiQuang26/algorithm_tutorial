#include <bits/stdc++.h>
using namespace std;

int findMaxInArray(double a[], int l, int r)
{

	if (l >= r)
	{
		return r;
	}
	int m = (l + r) / 2;
	int vt_max_l = findMaxInArray(a, l, m);
	int vt_max_r = findMaxInArray(a, m + 1, r);
	if (a[vt_max_l] > a[vt_max_r])
		return vt_max_l;
	return vt_max_r;
}

int main()
{
	int n = 15;
	double a[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	cout << a[findMaxInArray(a, 0, n - 1)];
	return 0;
}
