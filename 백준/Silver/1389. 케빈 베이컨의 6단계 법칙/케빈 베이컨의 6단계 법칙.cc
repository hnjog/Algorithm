#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n, m;

int bacon(unordered_map<int, vector<int>>& pfmap, int people)
{
	int sums = 0;

	struct fInfo
	{
		int now;
		int nowCost;
	};

	queue<fInfo> q;
	q.push({ people,0 });

	vector<int> v(n + 1);

	while (q.empty() == false)
	{
		int now = q.front().now;
		int nowCost = q.front().nowCost;
		q.pop();

		if (v[now] != 0)
			continue;

		v[now] = nowCost;

		for (int next : pfmap[now])
		{
			q.push({ next,nowCost + 1 });
		}
	}

	for (int i : v)
	{
		sums += i;
	}

	return sums;
}

int main()
{
	cin >> n >> m;

	unordered_map<int, vector<int>> pfmap;
	vector<int> vec(n+1,0);

	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;

		pfmap[t1].push_back(t2);
		pfmap[t2].push_back(t1);
	}

	for (int i = 1; i <= n; i++)
	{
		vec[i] = bacon(pfmap, i);
	}

	int result = -1;
	int resultCost = INT_MAX;

	for (int i = 1; i <= n; i++)
	{
		if (vec[i] < resultCost)
		{
			result = i;
			resultCost = vec[i];
		}
	}

	cout << result;

	return 0;
}