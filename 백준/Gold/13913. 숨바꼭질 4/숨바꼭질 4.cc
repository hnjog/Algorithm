#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct infos
{
	int now, prev;
	int nowCost;
};

int main()
{
	int n, k;
	cin >> n >> k;

	// 현재 위치, 시간
	queue<infos> q;
	unordered_map<int, int> visit;
	unordered_map<int, int> routes;

	int bestTime = -1;
	int bestCount = 0;

	q.push({ k,0 });
	routes[k] = k;

	while (q.empty() == false)
	{
		int nowPos = q.front().now;
		int nowTime = q.front().nowCost;
		int prev = q.front().prev;
		q.pop();

		if (bestTime != -1 &&
			nowTime > bestTime)
			break;

		if (visit.find(nowPos) != visit.end() &&
			visit[nowPos] < nowTime)
			continue;

		visit[nowPos] = nowTime;
		routes[nowPos] = prev;

		if (nowPos == n)
		{
			if (bestTime == -1 ||
				nowTime == bestTime)
			{
				bestTime = nowTime;
				bestCount++;
				continue;
			}
		}

		if (nowPos % 2 == 0)
			q.push({ nowPos / 2,nowPos,nowTime + 1 });

		q.push({ nowPos - 1,nowPos,nowTime + 1 });
		q.push({ nowPos + 1,nowPos,nowTime + 1 });
	}

	cout << bestTime << '\n';

	int start = n;
	int target = k;

	while (start != target)
	{
		cout << start << " ";
		start = routes[start];
	}

	cout << k;

	return 0;
}