#include<iostream>
#include<unordered_map>
#include<limits.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	unordered_map<long, int> um;

	for (int i = 0; i < n; i++)
	{
		long l;
		cin >> l;
		um[l]++;
	}

	long mv = LONG_MAX;
	int count = 0;

	for (const auto& p : um)
	{
		if (p.second > count)
		{
			count = p.second;
			mv = p.first;
		}
		else if (p.second == count)
		{
			if (mv > p.first)
				mv = p.first;
		}
	}

	cout << mv;

	return 0;
}