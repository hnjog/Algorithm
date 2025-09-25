#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

int n, m;

struct posInfo
{
	int y, x;
	int idx;
};

int FindParent(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = FindParent(pv, pv[x]);
}

bool Union(vector<int>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a] = b;

	return true;
}

struct Edge
{
	int s, t,cost;
};

void FindShortDis(const vector<string>& maps, const posInfo& start, vector<Edge>& outEdges, map<pair<int, int>, int>& keyMaps)
{
	struct qInfos
	{
		int y, x;
		int cost;
	};

	struct Compare
	{
		bool operator()(qInfos& a, qInfos& b)
		{
			return a.cost > b.cost;
		}
	};

	const int dirY[4] = { -1,0,1,0 };
	const int dirX[4] = { 0,1,0,-1 };

	priority_queue<qInfos, vector<qInfos>, Compare> pq;
	vector<vector<bool>> visit(n, vector<bool>(n, false));
	pq.push({ start.y,start.x,0 });

	while (pq.empty() == false)
	{
		int cy = pq.top().y;
		int cx = pq.top().x;
		int cCost = pq.top().cost;
		pq.pop();

		if (cy < 0 || cy >= n ||
			cx < 0 || cx >= n)
			continue;

		if (maps[cy][cx] == '1')
			continue;

		if (visit[cy][cx])
			continue;

		visit[cy][cx] = true;

		if (maps[cy][cx] == 'K' &&
			keyMaps[{cy, cx}] != start.idx)
		{
			outEdges.emplace_back(Edge{start.idx,keyMaps[{cy, cx}],cCost});
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			pq.push(qInfos{ cy + dirY[i],cx + dirX[i],cCost + 1});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<string> maps(n);

	vector<posInfo> keys;
	keys.reserve(m + 1);

	map<pair<int, int>, int> keyMaps;

	int flag = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> maps[i];
		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] == 'S' ||
				maps[i][j] == 'K')
			{
				posInfo p;
				p.y = i;
				p.x = j;
				if (maps[i][j] == 'S')
				{
					p.idx = 0;
				}
				else
				{
					p.idx = flag;
					keyMaps[{i, j}] = flag;
					flag++;
				}
				
				keys.emplace_back(p);
			}
			
		}
	}

	vector<Edge> sEdges;

	for (int i = 0; i <= m; i++)
	{
		FindShortDis(maps, keys[i], sEdges,keyMaps);
	}

	sort(sEdges.begin(), sEdges.end(), []
	(const Edge& a, const Edge& b)
		{
			return a.cost < b.cost;
		}
	);

	int answer = 0;
	int kCount = 0;
	vector<int> pv(m + 1);
	for (int i = 0; i <= m; i++)
		pv[i] = i;

	for (auto& e : sEdges)
	{
		if (Union(pv, e.s, e.t))
		{
			answer += e.cost;
			kCount++;
			if (kCount == m)
				break;
		}
	}

	int s = FindParent(pv,0);

	for (int i = 1; i <= m; i++)
	{
		if (s != FindParent(pv, i))
		{
			cout << -1;
			return 0;
		}
	}

	cout << answer;

	return 0;
}