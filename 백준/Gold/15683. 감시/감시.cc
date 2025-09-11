#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

struct pos
{
	int y, x;
};

int n, m;

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0, 1,0,-1 };

vector<pos> setView(vector<vector<int>>& map, const pos& p, int mainDir)
{
	int y = p.y;
	int x = p.x;

	int ny = y, nx = x;

	vector<pos> ret;

	switch (map[y][x])
	{
	case 1:
	{
		while (true)
		{
			ny += dirY[mainDir];
			nx += dirX[mainDir];

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
				break;

			if (map[ny][nx] <= 0)
			{
				map[ny][nx]--;
				ret.push_back({ ny,nx });
			}

			if (map[ny][nx] == 6)
				break;
		}
	}
	break;
	case 2:
	{
		int nny = y, nnx = x;
		bool s1 = false, s2 = false;
		while (true)
		{
			if (s1 == false)
			{
				ny += dirY[mainDir];
				nx += dirX[mainDir];
			}

			if (s2 == false)
			{
				nny -= dirY[mainDir];
				nnx -= dirX[mainDir];
			}

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
			{
				s1 = true;
			}

			if (s1 == false &&
				map[ny][nx] <= 0)
			{
				map[ny][nx]--;
				ret.push_back({ ny,nx });
			}

			if (s1 == false &&
				map[ny][nx] == 6)
			{
				s1 = true;
			}

			if (nny < 0 || nny >= n ||
				nnx < 0 || nnx >= m)
			{
				s2 = true;
			}

			if (s2 == false &&
				map[nny][nnx] <= 0)
			{
				map[nny][nnx]--;

				ret.push_back({ nny,nnx });
			}

			if (s2 == false &&
				map[nny][nnx] == 6)
			{
				s2 = true;
			}

			if (s1 && s2)
				break;
		}
	}
	break;
	case 3:
	{
		int subDir = mainDir - 1;
		if (subDir < 0)
			subDir = 3;

		int nny = y, nnx = x;
		bool s1 = false, s2 = false;
		while (true)
		{
			if (s1 == false)
			{
				ny += dirY[mainDir];
				nx += dirX[mainDir];
			}

			if (s2 == false)
			{
				nny += dirY[subDir];
				nnx += dirX[subDir];
			}


			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
			{
				s1 = true;
			}

			if (s1 == false &&
				map[ny][nx] <= 0)
			{
				map[ny][nx]--;

				ret.push_back({ ny,nx });
			}

			if (s1 == false &&
				map[ny][nx] == 6)
			{
				s1 = true;
			}

			if (nny < 0 || nny >= n ||
				nnx < 0 || nnx >= m)
			{
				s2 = true;
			}

			if (s2 == false &&
				map[nny][nnx] <= 0)
			{
				map[nny][nnx]--;

				ret.push_back({ nny,nnx });
			}

			if (s2 == false &&
				map[nny][nnx] == 6)
			{
				s2 = true;
			}

			if (s1 && s2)
				break;
		}
	}
	break;
	case 4:
	{
		int subDir = mainDir - 1;
		if (subDir < 0)
			subDir = 3;

		int subDir2 = mainDir + 1;
		if (subDir2 > 3)
			subDir2 = 0;

		int nny = y, nnx = x;
		int nnny = y, nnnx = x;
		bool s1 = false, s2 = false, s3 = false;
		while (true)
		{
			if (s1 == false)
			{
				ny += dirY[mainDir];
				nx += dirX[mainDir];
			}

			if (s2 == false)
			{
				nny += dirY[subDir];
				nnx += dirX[subDir];
			}

			if (s3 == false)
			{
				nnny += dirY[subDir2];
				nnnx += dirX[subDir2];
			}

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
			{
				s1 = true;
			}

			if (s1 == false &&
				map[ny][nx] <= 0)
			{
				map[ny][nx]--;

				ret.push_back({ ny,nx });
			}

			if (s1 == false &&
				map[ny][nx] == 6)
			{
				s1 = true;
			}

			if (nny < 0 || nny >= n ||
				nnx < 0 || nnx >= m)
			{
				s2 = true;
			}

			if (s2 == false &&
				map[nny][nnx] <= 0)
			{
				map[nny][nnx]--;
				ret.push_back({ nny,nnx });
			}

			if (s2 == false &&
				map[nny][nnx] == 6)
			{
				s2 = true;
			}

			if (nnny < 0 || nnny >= n ||
				nnnx < 0 || nnnx >= m)
			{
				s3 = true;
			}

			if (s3 == false &&
				map[nnny][nnnx] <= 0)
			{
				map[nnny][nnnx]--;
				ret.push_back({ nnny,nnnx });
			}

			if (s3 == false &&
				map[nnny][nnnx] == 6)
			{
				s3 = true;
			}

			if (s1 && s2 && s3)
				break;
		}
	}
	break;
	case 5:
	{
		int subDir = mainDir - 1;
		if (subDir < 0)
			subDir = 3;

		int subDir2 = mainDir + 1;
		if (subDir2 > 3)
			subDir2 = 0;

		int subDir3 = mainDir + 2;
		if (subDir3 > 3)
			subDir3 = 0;

		int nny = y, nnx = x;
		int nnny = y, nnnx = x;
		int nnnny = y, nnnnx = x;
		bool s1 = false, s2 = false, s3 = false, s4 = false;
		while (true)
		{
			if (s1 == false)
			{
				ny += dirY[mainDir];
				nx += dirX[mainDir];
			}

			if (s2 == false)
			{
				nny += dirY[subDir];
				nnx += dirX[subDir];
			}

			if (s3 == false)
			{
				nnny += dirY[subDir2];
				nnnx += dirX[subDir2];
			}

			if (s4 == false)
			{
				nnnny += dirY[subDir3];
				nnnnx += dirX[subDir3];
			}

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
			{
				s1 = true;
			}

			if (s1 == false &&
				map[ny][nx] <= 0)
			{
				map[ny][nx]--;
			}

			if (s1 == false &&
				map[ny][nx] == 6)
			{
				s1 = true;
			}

			if (nny < 0 || nny >= n ||
				nnx < 0 || nnx >= m)
			{
				s2 = true;
			}

			if (s2 == false &&
				map[nny][nnx] <= 0)
			{
				map[nny][nnx]--;
			}

			if (s2 == false &&
				map[nny][nnx] == 6)
			{
				s2 = true;
			}

			if (nnny < 0 || nnny >= n ||
				nnnx < 0 || nnnx >= m)
			{
				s3 = true;
			}

			if (s3 == false &&
				map[nnny][nnnx] <= 0)
			{
				map[nnny][nnnx]--;
			}

			if (s3 == false &&
				map[nnny][nnnx] == 6)
			{
				s3 = true;
			}

			if (nnnny < 0 || nnnny >= n ||
				nnnnx < 0 || nnnnx >= m)
			{
				s4 = true;
			}

			if (s4 == false &&
				map[nnnny][nnnnx] <= 0)
			{
				map[nnnny][nnnnx]--;
			}

			if (s4 == false &&
				map[nnnny][nnnnx] == 6)
			{
				s4 = true;
			}

			if (s1 && s2 && s3 && s4)
				break;
		}
	}
	break;
	}

	return ret;
}

int recur(vector<vector<int>>& map, vector<pos>& cameraPoss, int idx)
{
	// -1 -2 처럼 보고 있는 시야를 중첩할 예정시킬 생각임
	int cSize = cameraPoss.size();
	if (idx == cSize)
	{
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 0)
					ret++;
			}
		}

		return ret;
	}

	int ret = INT_MAX;
	for (int i = 0; i < 4; i++)
	{
		vector<pos> poss = setView(map, cameraPoss[idx], i);
		ret = min(ret, recur(map, cameraPoss, idx + 1));
		if (ret == 0)
			return 0;
		
		for (auto& p : poss)
		{
			int y = p.y;
			int x = p.x;
			map[y][x]++;
		}

		if (map[cameraPoss[idx].y][cameraPoss[idx].x] == 2 &&
			i > 2)
			break;
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<pos> cameraPoss, crossSet;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
            if(map[i][j] == 6)
                continue;
            
			if (map[i][j] > 0)
			{
				if (map[i][j] == 5)
					crossSet.push_back({ i,j });
				else
					cameraPoss.push_back({ i,j });
			}
		}
	}

	for (auto& p : crossSet)
	{
		setView(map, p, 0);
	}

	cout << recur(map, cameraPoss, 0);


	return 0;
}