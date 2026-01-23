#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

typedef pair<int, int> pii;

pii start, goal;

struct infos
{
	int y, x;
	int gc;
	int gnc;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		if (a.gc == b.gc)
			return a.gnc > b.gnc;

		return a.gc > b.gc;
	}
};

pii getV(vector<string>& maps)
{
	int n = maps.size();
	int m = maps[0].size();

	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ start.first,start.second,0,0 });

	vector<vector<pii>> gcs(n, vector<pii>(m, { 1e9,1e9 }));

	while (pq.empty() == false)
	{
		int nowy = pq.top().y;
		int nowx = pq.top().x;
		int nowgc = pq.top().gc;
		int nowgnc = pq.top().gnc;
		pq.pop();

		if (nowy < 0 || nowy >= n ||
			nowx < 0 || nowx >= m)
			continue;

		if (gcs[nowy][nowx].first < nowgc)
			continue;

		if (gcs[nowy][nowx].first == nowgc)
		{
			if (gcs[nowy][nowx].second <= nowgnc)
				continue;
		}

		gcs[nowy][nowx].first = nowgc;
		gcs[nowy][nowx].second = nowgnc;

		if (nowy == goal.first &&
			nowx == goal.second)
		{
			return { nowgc,nowgnc };
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + dirY[i];
			int nx = nowx + dirX[i];
			int ngc = nowgc;
			int ngnc = nowgnc;

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
				continue;

			if (maps[ny][nx] == 'g')
			{
				ngc++;
			}
			else if(maps[ny][nx] == '.')
			{
				for (int j = 0; j < 4; j++)
				{
					int nny = ny + dirY[j];
					int nnx = nx + dirX[j];

					if (nny < 0 || nny >= n ||
						nnx < 0 || nnx >= m)
						continue;

					if (maps[nny][nnx] == 'g')
					{
						ngnc++;
						break;
					}
				}
			}

			pq.push({ ny,nx,ngc,ngnc });
		}
	}

	return { -1,-1};
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> maps(n);

	for (int i = 0; i < n; i++)
	{
		cin >> maps[i];
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 'S')
			{
				start.first = i;
				start.second = j;
			}
			else if (maps[i][j] == 'F')
			{
				goal.first = i;
				goal.second = j;
			}
		}
	}

	pii r = getV(maps);

	cout << r.first << ' ' << r.second;

	return 0;
}