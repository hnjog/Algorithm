#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

struct pos
{
	int p;
	int cost;
};

struct Compare
{
	bool operator()(const pos& a, const pos& b)
	{
		if (a.cost == b.cost)
			return a.p < b.p;

		return a.cost > b.cost;
	}
};

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0 ,-1 };
const int dice[6] = { 1,2,3,4,5,6 };

unordered_map<int, int> ladders;
unordered_map<int, int> snakes;

int maps[101];

int bfs()
{
	const int start = 1;
	const int end = 100;

	for (int i = 0; i <= 100; i++)
		maps[i] = INT_MAX;
	
	priority_queue<pos,vector<pos>,Compare> pq;
	pq.push({ start,0 });

	while (pq.empty() == false)
	{
		pos p = pq.top();
		pq.pop();

		int nowP = p.p;
		int nowC = p.cost;
		if (nowP > end)
			continue;

		if (nowC > maps[nowP])
			continue;

		maps[nowP] = nowC;

		if (nowP == end)
		{
			break;
		}

		if (ladders.find(nowP) != ladders.end() ||
			snakes.find(nowP) != snakes.end())
		{
			//위치가 뱀이나 사다리인 경우 반드시 그쪽으로 이동해야 함

			if (ladders.find(nowP) != ladders.end())
			{
				pq.push({ ladders[nowP],nowC});
			}
			else
			{
				pq.push({ snakes[nowP],nowC });
			}
		}
		else
		{
			// 그게 아니면 주사위 굴림
			for (int i = 5; i >= 0; i--)
			{
				pq.push({ nowP + dice[i], nowC + 1 });
			}
		}
		
	}

	return maps[end];
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int t1,t2;
		cin >> t1 >> t2;
		ladders[t1] = t2;
	}

	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		snakes[t1] = t2;
	}

	cout << bfs();
}