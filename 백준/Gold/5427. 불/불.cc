#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int r, c;

struct infos
{
	int y, x;
	int cost;
	bool bPlayer;
};

int bfs(vector<string>& maps, const pair<int, int>& start, const vector<pair<int, int>> fires)
{
	vector<vector<bool>> visit(r, vector<bool>(c, false));
	queue<infos> pq;
	pq.push({ start.first,start.second,0,true });

	for (const auto& f : fires)
	{
		pq.push({ f.first,f.second,-1,false });
	}

	while (pq.empty() == false)
	{
		int nowy = pq.front().y;
		int nowx = pq.front().x;
		int nowcost = pq.front().cost;
		bool isPlayer = pq.front().bPlayer;
		pq.pop();

		if (isPlayer)
		{
			if (nowy < 0 ||
				nowy > r - 1 ||
				nowx < 0 ||
				nowx > c - 1)
			{
				return nowcost;
			}

			if (maps[nowy][nowx] == '*')
				continue;

			for (int i = 0; i < 4; i++)
			{
				int ny = nowy + dirY[i];
				int nx = nowx + dirX[i];

				if (ny < 0 || ny >= r ||
					nx < 0 || nx >= c)
				{
					pq.push({ ny,nx,nowcost + 1,true }); // 탈출 조건
					continue;
				}

				if (maps[ny][nx] == '#' || maps[ny][nx] == '*')
					continue;

				if (visit[ny][nx])
					continue;

				visit[ny][nx] = true;
				pq.push({ ny,nx,nowcost + 1,true });
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int ny = nowy + dirY[i];
				int nx = nowx + dirX[i];

				if (ny < 0 || ny >= r ||
					nx < 0 || nx >= c)
					continue;

				if (maps[ny][nx] == '#' || maps[ny][nx] == '*')
					continue;

				maps[ny][nx] = '*';
				pq.push({ ny,nx,nowcost + 1,false });
			}
		}

	}

	return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		cin >> c >> r;

		vector<string> maps(r);

		pair<int, int> start;
		vector<pair<int, int>> fires;

		for (int i = 0; i < r; i++)
		{
			cin >> maps[i];
			for (int j = 0; j < c; j++)
			{
				if (maps[i][j] == '@')
				{
					start.first = i;
					start.second = j;
				}
				else if (maps[i][j] == '*')
				{
					fires.push_back({ i,j });
				}
			}
		}

		int v = bfs(maps, start, fires);
		if (v == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << v << '\n';

		t--;
	}

	return 0;
}