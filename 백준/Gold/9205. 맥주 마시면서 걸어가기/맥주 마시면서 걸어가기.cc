#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<math.h>

using namespace std;

struct pos
{
	int y, x;
};

inline int Mahatten(const pos& a, const pos& b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

inline bool CanReach(const pos& a, const pos& b)
{
	return Mahatten(a, b) <= 1000 ? true : false;
}

bool bfs(const pos& start, const pos& target, const vector<pos>& cVec)
{
	int cSize = cVec.size();

	if (cSize == 0)
	{
		return CanReach(start,target);
	}

	queue<pos> q;
	q.push(start);

	vector<bool> visit(cSize, false);

	while (q.empty() == false)
	{
		pos now = q.front();
		q.pop();

		if (CanReach(now, target))
			return true;

		for (int i = 0; i < cSize; i++)
		{
			if (visit[i] == false &&
				CanReach(now, cVec[i]))
			{
				visit[i] = true;
				q.push(cVec[i]);
			}
		}

	}

	return false;
}

int main()
{
	int t;
	cin >> t;

	while (t > 0)
	{
		int cNum;
		cin >> cNum;

		pos start, target;
		cin >> start.x >> start.y;
		vector<pos> cVec;
		for (int i = 0; i < cNum; i++)
		{
			pos t;
			cin >> t.x >> t.y;
			cVec.push_back(t);
		}

		cin >> target.x >> target.y;

		if (bfs(start, target, cVec))
		{
			cout << "happy" << '\n';
		}
		else
		{
			cout << "sad" << '\n';
		}

		t--;
	}


	return 0;
}