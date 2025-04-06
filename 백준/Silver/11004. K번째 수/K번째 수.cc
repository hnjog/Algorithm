#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct Compare1
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

struct Compare2
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
    cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	priority_queue<int, vector<int>, Compare1> pq1;
	priority_queue<int, vector<int>, Compare2> pq2;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		pq1.push(t);
		if (pq1.size() > k)
			pq1.pop();
	}

	for (int i = 0; i < k; i++)
	{
		int t = pq1.top();
		pq2.push(t);
		pq1.pop();
	}

	for (int i = 0; i < k - 1; i++)
		pq2.pop();

	cout << pq2.top();
}