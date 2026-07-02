#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

int GetBestVisit(unordered_map<int, vector<int>>& maps, int start)
{
	queue<pair<int,int>> q;
	q.push({ start,0 });

	unordered_set<int> visit;

	int best = 0;
	int bestDepth = -1;

	while (q.empty() == false)
	{
		int now = q.front().first;
		int nowD = q.front().second;
		q.pop();

		if (visit.find(now) != visit.end())
			continue;

		visit.insert(now);

		if (nowD > bestDepth)
		{
			bestDepth = nowD;
			best = now;
		}
		else if (nowD == bestDepth)
		{
			if (now > best)
				best = now;
		}
		

		for (int next : maps[now])
		{
			q.push({ next,nowD + 1 });
		}
	}

	return best;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		int len, start;
		cin >> len >> start;

		unordered_map<int, vector<int>> maps;
		for (int i = 0; i < len / 2; i++)
		{
			int s, t;
			cin >> s >> t;
			maps[s].push_back(t);
		}

		cout << '#' << test_case << ' ' << GetBestVisit(maps, start) << '\n';
	}
	return 0;
}