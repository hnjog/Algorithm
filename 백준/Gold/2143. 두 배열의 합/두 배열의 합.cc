#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> GetSubSumVec(const vector<int>& origin)
{
	int n = origin.size();

	vector<int> sums(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		sums[i + 1] = sums[i] + origin[i];
	}

	vector<int> rets;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int cSum = sums[j] - sums[i];
			rets.push_back(cSum);
		}
	}

	sort(rets.begin(), rets.end());

	return rets;
}

long GetCount(const vector<int>& vec, int t)
{
	auto l = lower_bound(vec.begin(), vec.end(), t);
	auto u = upper_bound(vec.begin(), vec.end(), t);
	return u - l;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	int n,m;
	cin >> n;

	vector<int> va(n);

	for (int i = 0; i < n; i++)
	{
		cin >> va[i];
	}

	cin >> m;
	vector<int> vb(m);

	for (int i = 0; i < m; i++)
	{
		cin >> vb[i];
	}

	vector<int> vva = GetSubSumVec(va);
	vector<int> vvb = GetSubSumVec(vb);

	long count = 0;

	for (int i = 0; i < vva.size(); i++)
	{
		int tv = t - vva[i];
		count += GetCount(vvb, tv);
	}

	cout << count;

	return 0;
}