#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long long ull;

int nowOneCount(ull n)
{
	int count = 0;

	int one = 1;

	while (n >= 1)
	{
		int v = n & one;
		if (v == 1)
			count++;

		n = n >> 1;
	}

	return count;
}

int main()
{
	int n, k;
	cin >> n >> k;

	ull now = n;

	while (nowOneCount(now) > k)
	{
		now++;
	}

	cout << now - n;

	return 0;
}