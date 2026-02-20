#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int idx = 10;
	int v = 1;

	int s = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i >= idx)
		{
			idx *= 10;
			v++;
		}
		s += v;
	}

	cout << s;

	return 0;
}