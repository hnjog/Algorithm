#include<vector>
#include<queue>

using namespace std;

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

struct infos
{
	int y, x, cost;
};

int solution(vector<vector<int> > maps)
{
	int n = maps.size();
	int m = maps[0].size();

	queue<infos> q;
	q.push({ 0,0,1 });

	while (q.empty() == false)
	{
		int nowy = q.front().y;
		int nowx = q.front().x;
		int nowcost = q.front().cost;
		q.pop();

		if (nowy < 0 || nowy >= n ||
			nowx < 0 || nowx >= m)
			continue;

		if (maps[nowy][nowx] <= 0)
			continue;

		if (nowy == n - 1 &&
			nowx == m - 1)
		{
			return nowcost;
		}

		maps[nowy][nowx] = 0;

		for (int i = 0; i < 4; i++)
		{
			q.push({ nowy + dirY[i],nowx + dirX[i],nowcost + 1 });
		}
	}

	return -1;
}
