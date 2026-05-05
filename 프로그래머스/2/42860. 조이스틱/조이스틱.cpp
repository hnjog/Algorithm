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
	/*
		일단 각 문자에서 필요한 조작 횟수는 존재함
		- min('z' - c, c)

		고민해볼 점?
		앞 or 뒤로 시작하였을때,
		어떤 것이 최소 횟수인지를 고민

		- 필요 조작 횟수가 0 이 아니라면 결국 반드시 방문해야 함
		- 그리고 대부분의 경우, 0을 밟아서 통과하는 것이 더 빠를 수 있음
		- 그렇기에 시작점 근처(1과 마지막)에 0이 있는 경우(그것도 1개만 존재할때)가 아니면 그냥 밟아서 가야 함
		  (그 경우에만 -1)
	*/

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