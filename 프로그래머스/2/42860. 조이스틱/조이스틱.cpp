#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int findMin(vector<int>& map)
{
	unordered_set<int> idxs;

	for (int i = 0; i < map.size(); i++)
	{
		if (map[i] > 0)
			idxs.insert(i);
	}

	struct pos
	{
		int idx;
		unordered_set<int> idxs;
		int count;
	};

	queue<pos> q;

	q.push({ 0,unordered_set<int>(),0 });

	while (q.empty() == false)
	{
		int i = q.front().idx;
		if (i < 0)
		{
			i = map.size() - 1;
		}
		else if (i >= map.size())
		{
			i = 0;
		}

		unordered_set<int> us = move(q.front().idxs);
		int nowC = q.front().count;
		int vv = us.size();
		q.pop();

		if (us.size() == idxs.size())
		{
			return nowC;
		}

		if (nowC >= 40)
			continue;

		if (map[i] > 0)
		{
			us.insert(i);
		}

		q.push({ i - 1,us,nowC + 1 });
		q.push({ i + 1,us,nowC + 1 });
	}

	return 0;
}

int solution(string name) {
	int answer = 0;
	int ssize = name.size();

	vector<int> counts;
	counts.reserve(ssize);

	for (char c : name)
	{
		int v = min(c - 'A', 'Z' - c + 1);
		if (v == 0)
			counts.push_back(0);
		else
			counts.push_back(1);
		answer += v;
	}

	if (answer == 0)
		return 0;

	int c = findMin(counts);
	answer += c;
	answer--;

	return answer;
}