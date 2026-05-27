#include <vector>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

const int dirCount = 4;
const int dy[] = { 1, 0, -1, 0 };
const int dx[] = { 0, 1, 0, -1 };


int find(vector<int>& parent, int x)
{
	if (parent[x] != x) {
		parent[x] = find(parent, parent[x]);
	}
	return parent[x];
}

void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
	int rootX = find(parent, x);
	int rootY = find(parent, y);

	if (rootX != rootY)
	{
		if (rank[rootX] > rank[rootY])
		{
			parent[rootY] = rootX;
		}
		else if (rank[rootX] < rank[rootY])
		{
			parent[rootX] = rootY;
		}
		else
		{
			parent[rootY] = rootX;
			rank[rootX]++;
		}
	}
}

int solution(vector<vector<int>> land, int height) {
	// 전형적인 탐색 문제인줄 알았는데
	// 실상은 그래프 문제이며, 그 중에서도 mst와 관련된 문제...

	struct Edge {
		int cost;
		int x1, y1, x2, y2;
		bool operator<(const Edge& other) const
		{
			return cost < other.cost;
		}
	};

	const int n = land.size();
	vector<Edge> edges;

	// land 돌면서 '간선' 만들기
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			for (int i = 0; i < dirCount; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				int cost = abs(land[x][y] - land[nx][ny]);
				if (cost > height)
				{
					edges.push_back({ cost, x, y, nx, ny });
				}
				else
				{
					edges.push_back({ 0, x, y, nx, ny });
				}
			}
		}
	}

	sort(edges.begin(), edges.end());

	vector<int> parent(n * n);
	vector<int> rank(n * n, 0);

	// 처음엔 자기 자신을 부모로 설정 
	for (int i = 0; i < n * n; ++i)
	{
		parent[i] = i;
	}


	int answer = 0;
	for (const auto& edge : edges)
	{
		int x1 = edge.x1 * n + edge.y1;
		int x2 = edge.x2 * n + edge.y2;

		if (find(parent, x1) != find(parent, x2))
		{
			unite(parent, rank, x1, x2);
			answer += edge.cost;
		}
	}

	return answer;
}