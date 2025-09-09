#include<iostream>
#include<vector>

using namespace std;

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0, 1,0,-1 };

// 백트래킹 문제
// 그냥 카운트가 4가 될때까지
// 해당 점에서 가능한
// 모든 경우의 수를 탐색하면 될듯?
//

int n, m;

int best(vector<vector<int>>& map, vector<vector<bool>>& visit, int startY, int startX, int count,int nowSum)
{
	if (startY < 0 || startY >= n ||
		startX < 0 || startX >= m)
		return 0;

	if (visit[startY][startX])
		return 0;

	if (count == 3)
	{
		return nowSum + map[startY][startX];
	}

	int ret = 0;
	visit[startY][startX] = true;
	
	// ㅗ 모양을 찾으려면...
	for (int i = 0; i < 4; i++)
	{
		int ny = startY + dirY[i];
		int nx = startX + dirX[i];

		ret = max(ret, best(map, visit, ny, nx, count + 1, nowSum + map[startY][startX]));
	}

	// ㅗ 모양에 대한 예외처리
	if (count == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			int ny = startY + dirY[i];
			int nx = startX + dirX[i];
			int j = i + 1;

			if (j > 3)
				j = 0;
			int nny = startY + dirY[j];
			int nnx = startX + dirX[j];

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m ||
				nny < 0 || nny >= n ||
				nnx < 0 || nnx >= m ||
				visit[ny][nx] ||
				visit[nny][nnx])
				continue;

			ret = max(ret, nowSum + map[startY][startX] + map[ny][nx] + map[nny][nnx]);
		}
	}

	visit[startY][startX] = false;

	return ret;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> map(n,vector<int>(m,-1));
	vector<vector<bool>> visit(n,vector<bool>(m,false));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	int bestV = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			bestV = max(bestV, best(map,visit, i, j, 0, 0));

	cout << bestV;
	return 0;
}