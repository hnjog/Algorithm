#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	// 현재 위치, 시간
	queue<pair<int, int>> q;
	unordered_map<int,int> visit;

	int bestTime = -1;
	int bestCount = 0;

	q.push({ k,0 });

	while (q.empty() == false)
	{
		int nowPos = q.front().first;
		int nowTime = q.front().second;
		q.pop();

		if (bestTime != -1 &&
			nowTime > bestTime)
			break;

		if (visit.find(nowPos) != visit.end() &&
			visit[nowPos] < nowTime)
			continue;

		visit[nowPos] = nowTime;

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

		if(nowPos % 2 == 0)
			q.push({ nowPos / 2,nowTime + 1 });

		q.push({ nowPos - 1,nowTime + 1 });
		q.push({ nowPos + 1,nowTime + 1 });
	}

	cout << bestTime << '\n';
	cout << bestCount << '\n';

	return 0;
}