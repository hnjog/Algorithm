#include<iostream>
#include<vector>
#include<string>

using namespace std;

int r, c;

bool dfs(vector<string>& maps, int nowr, int nowc)
{
	if (nowr < 0 || nowr >= r)
		return false;

	if (maps[nowr][nowc] != '.')
		return false;

	maps[nowr][nowc] = 'x';

	if (nowc == c - 1)
		return true;

	if (dfs(maps, nowr - 1, nowc + 1))
		return true;

	if (dfs(maps, nowr, nowc + 1))
		return true;

	if (dfs(maps, nowr + 1, nowc + 1))
		return true;

	return false;
}

int main()
{
	cin >> r >> c;
	vector<string> maps(r);
	for (int i = 0; i < r; i++)
		cin >> maps[i];

	int answer = 0;
	for (int i = 0; i < r; i++)
	{
		if (dfs(maps, i, 0))
			answer++;
	}

	cout << answer;
}