#include<iostream>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int> minQ;
	priority_queue<int, vector<int>, greater<int>> maxQ;
	vector<int> ans;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;

		if (minQ.empty() || t <= minQ.top())
		{
			minQ.push(t);
			if (minQ.size() - maxQ.size() >= 2)
			{
				maxQ.push(minQ.top());
				minQ.pop();
			}
		}
		else // t가 minq의 top보다 큰 상황
		{
			maxQ.push(t);
			if (maxQ.size() > minQ.size())
			{
				minQ.push(maxQ.top());
				maxQ.pop();
			}
		}

		ans.push_back(minQ.top());
	}

	for (int i : ans)
	{
		cout << i << '\n';
	}

	return 0;
}