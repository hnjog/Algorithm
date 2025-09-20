#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

long long n, m;
vector<long long> times;
bool IsAcceptTime(long long targetTime)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += (targetTime / times[i]);
		if (sum >= m)
			return true;
	}

	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		times.push_back(t);
	}

	long long left = 0;
	long long right = LLONG_MAX;

	while (left < right)
	{
		long long mid = (left + right) / 2;

		if (IsAcceptTime(mid))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << left;

	return 0;
}