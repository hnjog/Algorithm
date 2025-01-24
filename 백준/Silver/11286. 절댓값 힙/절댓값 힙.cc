#include<iostream>
#include<queue>

using namespace std;

struct Compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;

		return abs(a) > abs(b);
	}

};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>, Compare> pq;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;

		if (t == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(t);
		}
	}

}