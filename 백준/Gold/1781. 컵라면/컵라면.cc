#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct problem
{
	int deadLine;
	long val;
};

struct Compare
{
	bool operator()(const problem& a, const problem& b)
	{
		if (a.deadLine == b.deadLine)
			return a.val < b.val;

		return a.deadLine > b.deadLine;
	}
};

struct Compare2
{
	bool operator()(const problem& a, const problem& b)
	{
		return a.val > b.val;
	}
};

int main()
{
	int n;
	cin >> n;

	priority_queue<problem, vector<problem>, Compare> pq;
	priority_queue<problem, vector<problem>, Compare2> pq2;

	for (int i = 0; i < n; i++)
	{
		problem p;
		cin >> p.deadLine >> p.val;
		pq.push(p);
	}

	while (pq.empty() == false)
	{
		problem p = pq.top();
		pq.pop();

		int time = p.deadLine;

		pq2.push(p);

		if (pq2.size() > time)
		{
			pq2.pop();
		}

		time++;
	}

	long sum = 0;

	while (pq2.empty() == false)
	{
		sum += pq2.top().val;
		pq2.pop();
	}

	cout << sum;

	return 0;
}