#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;

int main()
{
	string str;
	cin >> str;

	int s = 0;
	int zCount = 0;
	for (char c : str)
	{
		int cc = c - '0';
		if (cc == 0)
			zCount++;
		s += cc;
	}

	if (zCount == 0 ||
		s % 3 != 0)
	{
		cout << -1;
		return 0;
	}

	sort(str.begin(), str.end(),greater<char>());

	cout << str;

	return 0;
}