#include<iostream>
#include<vector>

using namespace std;

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> vec(n + 1);

	for (int i = 1; i <= n; i++)
	{
		vec[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int i1, i2;
		cin >> i1 >> i2;

		for (int j = 0; j <= (i2 - i1)/2; j++)
		{
			swap(vec[i1 + j], vec[i2 - j]);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << vec[i] << ' ';

	return 0;
}