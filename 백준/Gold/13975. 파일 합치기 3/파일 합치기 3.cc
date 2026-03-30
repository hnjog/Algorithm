#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for (; t > 0; t--)
	{
		int k;
		cin >> k;

		priority_queue<long,vector<long>,greater<long>> pq;
		for (int i = 0; i < k; i++)
		{
			long v;
			cin >> v;
			pq.push(v);
		}

		long sum = 0;

		while (pq.size() > 1)
		{
			long v1 = pq.top();
			pq.pop();
			long v2 = pq.top();
			pq.pop();

			sum += (v1 + v2);
			pq.push(v1 + v2);
		}

		cout << sum << '\n';
	}

	return 0;
}