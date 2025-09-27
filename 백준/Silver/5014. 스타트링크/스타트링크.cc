#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>

using namespace std;

int main()
{
	int full, start, target, upv, dov;
	cin >> full >> start >> target >> upv >> dov;

	queue<pair<int, int>> q; // 위치,비용
	q.push({ start,0 });

	unordered_set<int> visited;

	while (q.empty() == false)
	{
		int now = q.front().first;
		int nowCost = q.front().second;
		q.pop();

		if (now <= 0 || now > full)
			continue;

		if (visited.find(now) != visited.end())
			continue;

		visited.insert(now);

		if (now == target)
		{
			cout << nowCost;
			return 0;
		}

		q.push({ now + upv,nowCost + 1 });
		q.push({ now - dov,nowCost + 1 });
	}

	cout << "use the stairs";
	return 0;
}