#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	priority_queue<long,vector<long>,greater<long>> pq;

	for (long i = 0; i < n; i++)
	{
		long t;
		cin >> t;
		pq.push(t);
	}

	for (long i = 0; i < m; i++)
	{
		long t1 = pq.top();
		pq.pop();
		long t2 = pq.top();
		pq.pop();

		pq.push(t1 + t2);
		pq.push(t1 + t2);
	}

	long sum = 0;
	while (pq.empty() == false)
	{
		sum += pq.top();
		pq.pop();
	}

	cout << sum;

	return 0;
}