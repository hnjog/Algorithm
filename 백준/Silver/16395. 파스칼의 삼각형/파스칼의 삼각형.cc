#include<iostream>

using namespace std;

int pas[31][31] = { 0, };

int main()
{
	int n, k;
	cin >> n >> k;
	pas[1][1] = 1;

	for (int i = 2;i <=n;i++)
	{
		pas[i][1] = 1;
		pas[i][i] = 1;
		for (int j = 2; j < i; j++)
		{
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}

	cout << pas[n][k];
}