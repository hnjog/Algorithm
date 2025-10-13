#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct infos
{
	int start, end;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.end > b.end;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<infos> iv;
	priority_queue<infos, vector<infos>, Compare> pq;

	for (int i = 0; i < n; i++)
	{
		infos info;
		int t;
		cin >> t >> info.start >> info.end;
		iv.emplace_back(info);
	}

	sort(iv.begin(), iv.end(), []
	(const infos& a, const infos& b)
		{
			if (a.start == b.start)
				return a.end < b.end;

			return a.start < b.start;
		});

	int ans = 0;

	for (int i = 0; i < iv.size(); i++)
	{
		if (pq.empty())
		{
			pq.push(iv[i]);
		}
		else
		{
			while (pq.empty() == false &&
				pq.top().end <= iv[i].start)
			{
				pq.pop();
			}

			pq.push(iv[i]);
		}

		if (pq.size() > ans)
			ans = pq.size();
	}

	cout << ans;

	return 0;
}