#include<iostream>
#include<vector>

using namespace std;

unsigned int visit = 0; // 여기에 비트 플래그로 검사
int minV = 1e9;

bool IsAllVisit(int n)
{
	unsigned int checker = (1 << n) - 1;
	return checker == visit;
}

bool IsVisit(int n)
{
	return (visit & (1 << n)) != 0;
}

void VisitCheck(int num)
{
	visit |= (1 << num);
}

void UnVisitCheck(int num)
{
	visit &= ~(1 << num);
}

void dfs(vector<vector<int>>& maps, int now, int nowTime)
{
	int n = maps.size();
	if (IsAllVisit(n))
	{
		if (nowTime < minV)
			minV = nowTime;

		return;
	}

	if (nowTime >= minV)
		return;

	for (int i = 0; i < n; i++)
	{
		if (i == now)
			continue;

		if (IsVisit(i))
			continue;

		VisitCheck(i);
		dfs(maps, i, nowTime + maps[now][i]);
		UnVisitCheck(i);
	}

}

int main()
{
	int n, start;
	cin >> n >> start;

	vector<vector<int>> maps(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][k] + maps[k][j] < maps[i][j])
					maps[i][j] = maps[i][k] + maps[k][j];
			}
		}
	}

	VisitCheck(start);
	dfs(maps, start,0);

	cout << minV;

	return 0;
}