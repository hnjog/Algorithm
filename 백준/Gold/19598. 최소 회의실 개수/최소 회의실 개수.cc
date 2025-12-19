#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	int n;
	cin >> n;

	vector<pii> tv(n);

	for (int i = 0; i < n; i++)
	{
		cin >> tv[i].first >> tv[i].second;
	}

	sort(tv.begin(), tv.end(), []
	(const pii& a, const pii& b)
		{
			if (a.first == b.first)
				return a.second < b.second;

			return a.first < b.first;
		}
	);

	int maxV = 0;
	priority_queue<int,vector<int>,greater<int>> pq;

	int nowtime = 0;

	for (const pii& p : tv)
	{
		if (pq.empty() == false)
		{
			while (pq.empty() == false &&
				pq.top() <= p.first)
			{
				pq.pop();
			}
		}

		pq.push(p.second);

		if (maxV < pq.size())
			maxV = pq.size();
	}

	cout << maxV;

	return 0;
}