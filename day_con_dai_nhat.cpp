#include <bits/stdc++.h>
using namespace std;

int dayConDaiNhat(int a[], int n)
{

	int L[n];
	for (int i = 0; i < n; i++)
		L[i] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && L[j] + 1 > L[i])
			{
				L[i] = L[j] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << L[i] << " ";
	}
	cout << endl
		 << "--------------" << endl;
	int maxLength, max = *max_element(L, L + n);
	maxLength = max;
	stack<int> st;
	while (n > 0)
	{
		n--;
		if (max == L[n])
		{
			st.push(a[n]);
			max--;
		}
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

	cout << endl
		 << "------------------" << endl;

	return maxLength;
}

void showArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{

	srand(time(NULL));
	int n = 15;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}

	showArr(a, n);

	int chilArrLength = dayConDaiNhat(a, n);

	cout << chilArrLength;

	return 0;
}
