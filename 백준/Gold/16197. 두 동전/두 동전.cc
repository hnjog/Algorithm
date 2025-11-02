#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int n, m;

struct pos
{
	int y, x;
};

struct QIn
{
	pos c1;
	pos c2;
	int cost;
};

int bfs(vector<string>& t, pos& c1,pos& c2)
{
	queue<QIn> q;
	q.push({ c1, c2,0 });

	while (q.empty() == false)
	{
		pos nowC1 = q.front().c1;
		pos nowC2 = q.front().c2;
		int cost = q.front().cost;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			pos nC1 = {nowC1.y + dirY[i],nowC1.x + dirX[i]};
			pos nC2 = {nowC2.y + dirY[i],nowC2.x + dirX[i]};
			int nCost = cost + 1;

			if (nCost > 10)
				continue;

			if (nC1.y < 0 || nC1.y >= n ||
				nC1.x < 0 || nC1.x >= m ||
				nC2.y < 0 || nC2.y >= n ||
				nC2.x < 0 || nC2.x >= m)
			{
				// 둘다 나간 경우
				if ((nC1.y < 0 || nC1.y >= n ||
					nC1.x < 0 || nC1.x >= m) &&
					(nC2.y < 0 || nC2.y >= n ||
						nC2.x < 0 || nC2.x >= m))
					continue;

				return nCost;
			}

			if (t[nC1.y][nC1.x] == '#')
			{
				nC1 = nowC1;
			}

			if (t[nC2.y][nC2.x] == '#')
			{
				nC2 = nowC2;
			}

			q.push({ nC1,nC2,nCost });
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;
	vector<string> t(n);
	
	bool bC1 = false;
	pos c1, c2;

	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		for (int j = 0; j < m; j++)
		{
			if (t[i][j] == 'o')
			{
				if (bC1 == false)
				{
					c1.y = i;
					c1.x = j;
					bC1 = true;
				}
				else
				{
					c2.y = i;
					c2.x = j;
				}
			}
		}
	}

	cout << bfs(t, c1, c2);

	return 0;
}