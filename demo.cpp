#include <bits/stdc++.h>
using namespace std;

void show_config(int a[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

void init(int a[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
}

// 1234 1243 1324 1342 1423 1432 2134
void next_config(int a[], int n, bool *flag)
{
	int i = n - 1;
	while (i > 0 && a[i] > a[i + 1])
	{
		--i;
	}
	if (i == 0)
		*flag = true;
	else
	{
		int j = n;
		while (a[j] < a[i])
			--j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main()
{
	int n = 4;
	int a[100];
	bool flag = false;
	init(a, n);

	while (!flag)
	{
		show_config(a, n);
		next_config(a, n, &flag);
	}

	return 0;
}
