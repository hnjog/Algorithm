#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<long long> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	map<long long, long long> um;
	um[0] = 1;

	long long sum = 0;
	long long count = 0;

	for (int i = 0; i < n; i++)
	{
		sum += vec[i];
		
		if (um.find(sum - k) != um.end())
		{
			count += um[sum - k];
		}

		um[sum]++;
	}

	cout << count;

	return 0;
}