#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<math.h>

using namespace std;

struct pos
{
	int y, x;
	int count;
};

const int dirY[8] = { 1,2,2,1,-1,-2,-2,-1 };
const int dirX[8] = { -2,-1,1,2,2,1,-1,-2 };

int bfs(int l, int y, int x,int ty, int tx)
{
	queue<pos> q;
	q.push({ y,x,0 });

	vector<vector<int>> dp(l,vector<int>(l,INT_MAX));

	while (q.empty() == false)
	{
		pos p = q.front();
		q.pop();

		int ny = p.y;
		int nx = p.x;
		int nCount = p.count;

		if (ny < 0 || ny >= l ||
			nx < 0 || nx >= l)
			continue;

		if (ny == ty &&
			nx == tx)
			return nCount;

		if (dp[ny][nx] <= nCount)
			continue;
		
		dp[ny][nx] = nCount;

		for (int i = 0; i < 8; i++)
		{
			int nextY = ny + dirY[i];
			int nextX = nx + dirX[i];

			q.push({ nextY,nextX,nCount + 1 });
		}
	}

	return -1;
}


int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int l;
		cin >> l;

		int y, x;
		cin >> y >> x;
		int ty, tx;
		cin >> ty >> tx;

		cout << bfs(l,y,x,ty,tx) << '\n';
	}

}