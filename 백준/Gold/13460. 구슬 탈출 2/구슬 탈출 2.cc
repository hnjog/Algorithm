#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<limits.h>

using namespace std;

struct posInfo
{
	int y, x;

	bool operator==(const posInfo& other)
	{
		return y == other.y && x == other.x;
	}

	posInfo operator+(const posInfo& other)
	{
		return { y + other.y,x + other.x };
	}

};

enum dir
{
	D_down,
	D_right,
	D_up,
	D_left
};

struct moveInfo
{
	posInfo Red, Blue;
	int cost;
};

struct Compare
{
	bool operator()(const moveInfo& a, const moveInfo& b)
	{
		return a.cost > b.cost;
	}
};

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

posInfo Red, Blue, Gole;
int n, m;

int BFS(const vector<vector<char>>& maps)
{
	priority_queue<moveInfo, vector<moveInfo>, Compare> pq;
	pq.push({ Red,Blue,0 });

	map <pair<int, int>, set< pair<int, int>>> visited;

	while (pq.empty() == false)
	{
		posInfo nowRed = pq.top().Red;
		posInfo nowBlue = pq.top().Blue;
		int nowCost = pq.top().cost;
		pq.pop();

		// 두 위치는 같이 존재할 수 없음
		if (nowRed == nowBlue)
			continue;

		if (nowCost > 10)
			continue;

		if (nowRed == Gole)
		{
			return nowCost;
		}

		if (nowBlue == Gole)
			continue;

		if (visited[{nowRed.y, nowRed.x}].find({ nowBlue.y,nowBlue.x }) != visited[{nowRed.y, nowRed.x}].end())
		{
			continue;
		}

		visited[{nowRed.y, nowRed.x}].insert({ nowBlue.y,nowBlue.x });

		for (int i = 0; i < 4; i++)
		{
			posInfo nextRed = nowRed;
			posInfo nextBlue = nowBlue;

			bool bMoveRed = false;
			bool bStuckRed = false;

			bool bMoveBlue = false;
			bool bStuckBlue = false;

			while (bMoveRed == false ||
				bMoveBlue == false)
			{
				if(bMoveRed == false)
					nextRed = nextRed + posInfo{ dirY[i],dirX[i] };

				if (maps[nextRed.y][nextRed.x] == '#')
				{
					bMoveRed = true;
					bStuckRed = true;
					nextRed = nextRed + posInfo{ -dirY[i],-dirX[i] };
				}
				else if (nextRed == Gole)
				{
					bMoveRed = true;
				}

				if(bMoveBlue == false)
					nextBlue = nextBlue + posInfo{ dirY[i],dirX[i] };

				if (maps[nextBlue.y][nextBlue.x] == '#')
				{
					bMoveBlue = true;
					bStuckBlue = true;
					nextBlue = nextBlue + posInfo{ -dirY[i],-dirX[i] };
				}
				else if (nextBlue == Gole)
				{
					bMoveBlue = true;
				}
				
				if (nextRed == nextBlue)
				{
					if (bStuckRed)
					{
						nextBlue = nextBlue + posInfo{ -dirY[i],-dirX[i] };
					}
					else if(bStuckBlue)
					{
						nextRed = nextRed + posInfo{ -dirY[i],-dirX[i] };
					}
					break;
				}
			}

			pq.push({ nextRed,nextBlue,nowCost + 1 });
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;
	vector<vector<char>> maps;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		maps.push_back(vector<char>());
		for (int j = 0; j < m; j++)
		{
			char c = str[j];
			maps[i].push_back(c);

			if (c == 'B')
			{
				Blue.y = i;
				Blue.x = j;
			}

			if (c == 'R')
			{
				Red.y = i;
				Red.x = j;
			}

			if (c == 'O')
			{
				Gole.y = i;
				Gole.x = j;
			}
		}
	}

	cout << BFS(maps);

	return 0;
}