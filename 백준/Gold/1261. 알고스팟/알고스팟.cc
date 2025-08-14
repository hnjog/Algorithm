#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<string>

using namespace std;

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

struct info
{
	int nowY, nowX;
	int nowCost;
};

struct Compare
{
	bool operator()(const info& a, const info& b) const
	{
		return a.nowCost > b.nowCost;
	}
};

int best(vector<vector<int>>& miro)
{
	int n = miro.size();
	int m = miro[0].size();

	vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

	priority_queue<info, vector<info>, Compare> pq;
	pq.push({ 0,0,0 });

	while (pq.empty() == false)
	{
		int nowY = pq.top().nowY;
		int nowX = pq.top().nowX;
		int nowCost = pq.top().nowCost;
		pq.pop();

		if (dp[nowY][nowX] <= nowCost)
			continue;

		dp[nowY][nowX] = nowCost;

		if (nowY == n - 1 && nowX == m - 1)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];

			if (nextY < 0 || nextX < 0 ||
				nextY >= n || nextX >= m)
				continue;

			if (miro[nextY][nextX] == 0)
				pq.push({ nextY,nextX,nowCost });
			else
				pq.push({ nextY,nextX,nowCost + 1 });

		}
	}

	return dp[n - 1][m - 1];
}


int main()
{
	int m, n;
	cin >> m >> n;

	vector<vector<int>> miro(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++)
	{
		string ss;
		cin >> ss;
		for (int j = 0; j < m; j++)
		{
			miro[i][j] = ss[j] - '0';
		}
	}

	cout << best(miro);

	return 0;
}