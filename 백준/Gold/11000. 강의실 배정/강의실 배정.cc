#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct ins
{
	int start, end;
};

struct Compare
{
	bool operator()(const ins& a, const ins& b)
	{
		return a.end > b.end;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<ins> vec;

	for (int i = 0; i < n; i++)
	{
		ins ti;
		cin >> ti.start >> ti.end;
		vec.push_back(ti);
	}

	sort(vec.begin(), vec.end(), []
	(const ins& a, const ins& b) 
		{
			return a.start < b.start;
		}
	);

	priority_queue<ins, vector<ins>, Compare> pq;
	int fullSize = 1;

	for (ins& i : vec)
	{
		if (pq.empty())
		{
			pq.push(i);
			continue;
		}
		
		int startTime = i.start;

		while (pq.empty() == false)
		{
			int eTime = pq.top().end;

			if (eTime <= startTime)
			{
				pq.pop();
			}
			else
				break;
		}

		pq.push(i);

		if (pq.size() > fullSize)
			fullSize = pq.size();
	}

	cout << fullSize;
}