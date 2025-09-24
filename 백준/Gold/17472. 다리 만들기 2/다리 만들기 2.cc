#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

struct edge
{
	int s, t;
	int cost;
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

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

void MapMark(vector<vector<int>>& maps, int y, int x, int flag)
{
	if (y < 0 || y >= n ||
		x < 0 || x >= m)
		return;

	if (maps[y][x] != 1)
		return;

	maps[y][x] = flag;

	for (int i = 0; i < 4; i++)
	{
		MapMark(maps, y + dirY[i], x + dirX[i], flag);
	}
}

void MakeBridge(vector<vector<int>>& maps, vector<edge>& edgeVec, int y, int x, int flag,int dir, int dis)
{
	if (y < 0 || y >= n ||
		x < 0 || x >= m)
		return;

	if (maps[y][x] != 0)
	{
		if (maps[y][x] != flag &&
			dis > 1)
		{
			edgeVec.push_back({ flag,maps[y][x],dis });
		}

		return;
	}

	MakeBridge(maps, edgeVec, y + dirY[dir], x + dirX[dir], flag, dir, dis + 1);
}

void CheckBridge(vector<vector<int>>& maps, vector<edge>& edgeVec, int y, int x, int flag)
{
	for (int i = 0; i < 4; i++)
	{
		MakeBridge(maps, edgeVec, y + dirY[i], x + dirX[i], flag, i, 0);
	}
}

int main()
{
	// 푸는법?
	// 1. 각 map을 dfs 순회하며,
	//   0이 아닌 녀석들에 대하여 dfs 탐색
	//   이후 각 위치에 flag용 숫자들을 사용한다
	//   어떤 곳은 1번 섬, 2번 섬...
	// 
	// 2. 각 섬들에 대하여
	// 다른 섬을 연결하는 최단거리 다리를 놓음
	// (연결이 불가하다면 그냥 pass)
	// (어차피 다리가 겹치더라도 비용 각자 계산이므로)
	// (연결되면 edge를 통하여 
	//  시작점/끝점/다리비용 저장)
	// 
	// 3. mst
	// 크루스칼 이용하여
	// 다리비용 오름차순 정렬후
	// 최소 비용 구하기
	//
	//
	cin >> n >> m;

	vector<vector<int>> maps(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maps[i][j];

	int flag = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 1)
				MapMark(maps, i, j, flag++);
		}
	}

	vector<edge> edges;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] > 1)
			{
				CheckBridge(maps, edges, i, j, maps[i][j]);
			}
		}
	}

	sort(edges.begin(), edges.end(), []
	(const edge& a, const edge& b)
		{
			return a.cost < b.cost;
		});

	vector<int> parents(flag -2);
	for (int i = 0; i < flag-2; i++)
	{
		parents[i] = i;
	}

	int answer = 0;
	for (auto& e : edges)
	{
		if (Union(parents, e.s - 2, e.t - 2))
		{
			answer += e.cost;
		}
	}

	int p = FindParent(parents,0);
	for (int i = 1; i < flag - 2; i++)
	{
		if (p != FindParent(parents,i))
		{
			cout << -1;
			return 0;
		}
	}
	cout << answer;

	return 0;
}