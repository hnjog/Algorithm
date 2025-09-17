#include<iostream>
#include<math.h>

using namespace std;

long long getN(long dis)
{
	long long n = sqrt(dis);
	long long ns = n * n;

	if (ns == dis)
		return n * 2 - 1;

	if (dis > ns && dis <= ns + n)
		return n * 2;

	return n * 2 + 1;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> x >> y;

		cout << getN(y-x) << '\n';
	}

	return 0;
}