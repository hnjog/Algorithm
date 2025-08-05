#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_set>
#include<limits.h>

using namespace std;

struct pos
{
	pos(int y, int x)
	{
		this->y = y;
		this->x = x;
	}

	int y, x;
};

int ChickDis(const pos& a, const pos& b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

void dfs(const vector<pos>& houses, const vector<pos>& chicks, vector<int>& picked, int start, int m, int& result) 
{
	if (picked.size() == m) 
	{
		int total = 0;
		for (const auto& h : houses) 
		{
			int minDist = INT_MAX;
			for (int idx : picked) 
			{
				minDist = min(minDist, ChickDis(h, chicks[idx]));
			}
			total += minDist;
		}
		result = min(result, total);
		return;
	}

	// 치킨 집 m개 고르기
	for (int i = start; i < chicks.size(); i++) 
	{
		picked.push_back(i);
		dfs(houses, chicks, picked, i + 1, m, result);
		picked.pop_back();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<pos> houses, chicks;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;
			if (t == 1)
			{
				houses.emplace_back(pos(i, j));
			}
			else if (t == 2)
			{
				chicks.emplace_back(pos(i, j));
			}
		}
	}

	int result = INT_MAX;
	vector<int> selected;

	dfs(houses, chicks, selected, 0, m, result);

	cout << result;

	return 0;
}