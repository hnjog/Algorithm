#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int n;

int getv(unordered_map<int, vector<int>>& um, int v)
{
	queue<pair<int,int>> q;
	vector<int> visit(n,-1);

	q.push({ v,0 });

	int max = 0;

	while (q.empty() == false)
	{
		int now = q.front().first;
		int nowC = q.front().second;
		q.pop();

		if (visit[now] >= 0)
			continue;

		visit[now] = nowC;

		if (max < nowC)
			max = nowC;

		for (int next : um[now])
		{
			q.push({ next,nowC + 1 });
		}
	}

	return max;
}

int main()
{
	
	cin >> n;

	unordered_map<int, vector<int>> um;

	while (true)
	{
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 == -1)
			break;

		n1--;
		n2--;

		um[n1].push_back(n2);
		um[n2].push_back(n1);
	}

	vector<pair<int, int>> vs;
	for (int i = 0; i < n; i++)
	{
		int v = getv(um, i);

		vs.push_back({ i + 1,v });
	}

	sort(vs.begin(), vs.end(), []
	(const pair<int,int>& a, const pair<int, int>& b)
		{
			if (a.second == b.second)
				return a.first < b.first;

			return a.second < b.second;
		});

	int minV = vs[0].second;
	vector<int> ret;

	for (int i = 0; i < n; i++)
	{
		if (vs[i].second == minV)
		{
			ret.push_back(vs[i].first);
		}
		else
		{
			break;
		}
	}

	cout << minV << ' ' << ret.size() << '\n';
	for (int i : ret)
	{
		cout << i << ' ';
	}

	return 0;
}