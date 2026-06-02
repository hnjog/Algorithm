#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int GetMaxValue(unordered_map<int, vector<int>>& maps, vector<bool>& visit,int now)
{
	if (visit[now])
		return 0;

	visit[now] = true;
	int ret = 0;

	for (int next : maps[now])
	{
		int v = GetMaxValue(maps, visit, next);
		ret = max(ret, v);
	}

	visit[now] = false;

	return ret + 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		unordered_map<int, vector<int>> maps;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			maps[x].push_back(y);
			maps[y].push_back(x);
		}

		vector<bool> visit(n, false);
		int maxV = 0;

		for (int i = 0; i < n; i++)
		{
			maxV = max(maxV, GetMaxValue(maps,visit,i));
		}

		cout << '#' << test_case << ' ' << maxV << '\n';

	}
	return 0;
}