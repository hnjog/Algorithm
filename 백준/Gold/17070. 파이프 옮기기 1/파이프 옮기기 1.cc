#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;

const int diry[3] = { 0,1,1 };
const int dirx[3] = { 1,1,0 };

struct infos
{
	int y, x; // 파이프 끝
	int cost; // 파이프 방향
	int dir;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.cost < b.cost;
	}
};

int getValue(vector<vector<int>>& maps)
{
	vector<vector<int>> dp(n, vector<int>(n, 0));

	dp[0][0] = 0;
	dp[0][1] = 0;

	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ 0,1,0,0 });

	while (pq.empty() == false)
	{
		int nowy = pq.top().y;
		int nowx = pq.top().x;
		int nowCost = pq.top().cost;
		int nowDir = pq.top().dir;
		pq.pop();

		
		switch (nowDir)
		{
		case 0 :
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = nowy + diry[i];
				int nx = nowx + dirx[i];

				if (ny >= n || nx >= n)
					continue;

				if (maps[ny][nx] == 1)
					continue;

				if (i == 1)
				{
					if (maps[ny - 1][nx] == 1 ||
						maps[ny][nx - 1] == 1)
						continue;
				}

				dp[ny][nx]++;
				pq.push({ ny,nx,nowCost + 1,i });
			}
		}
		break;
		case 1:
		{
			for (int i = 0; i < 3; i++)
			{
				int ny = nowy + diry[i];
				int nx = nowx + dirx[i];

				if (ny >= n || nx >= n)
					continue;

				if (maps[ny][nx] == 1)
					continue;

				if (i == 1)
				{
					if (maps[ny - 1][nx] == 1 ||
						maps[ny][nx - 1] == 1)
						continue;
				}

				dp[ny][nx]++;

				pq.push({ ny,nx,nowCost + 1,i });
			}
		}
		break;
		case 2:
		{
			for (int i = 2; i > 0; i--)
			{
				int ny = nowy + diry[i];
				int nx = nowx + dirx[i];

				if (ny >= n || nx >= n)
					continue;

				if (maps[ny][nx] == 1)
					continue;

				if (i == 1)
				{
					if (maps[ny - 1][nx] == 1 ||
						maps[ny][nx - 1] == 1)
						continue;
				}

				dp[ny][nx]++;

				pq.push({ ny,nx,nowCost + 1,i });
			}
		}
		break;
		}
	}

	return dp[n - 1][n - 1];
}

int main()
{
	cin >> n;
	vector<vector<int>> maps(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> maps[i][j];
	}

	cout << getValue(maps);

	return 0;
}