#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vs(n, {-1,-1});

	for (int i = 0; i < n; i++)
	{
		cin >> vs[i].first >> vs[i].second;
	}

	sort(vs.begin(), vs.end(), [](const pair<int,int>& a, const pair<int, int>& b)
		{
			if (a.first == b.first)
				return a.second > b.second;

			return a.first < b.first;
		});

	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		int now = vs[i].first;
		int v = vs[i].second;

		pq.push(v);

		while(pq.size() > now)
			pq.pop();
	}

	int nowv = 0;

	while (pq.empty() == false)
	{
		nowv += pq.top();
		pq.pop();
	}

	cout << nowv;

	return 0;
}