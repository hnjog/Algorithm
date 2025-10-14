#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int ans = 0;

	vector<int> vecs(n);
	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		cin >> vecs[i];
	}

	sort(vecs.begin(), vecs.end());

	for (int i = 1; i < n; i++)
	{
		int v = vecs[i] - vecs[i-1];
		ans += v;
		pq.push(v);
	}

	int count = k - 1;

	while (count > 0)
	{
		ans -= pq.top();
		pq.pop();
		count--;
	}

	cout << ans;

	return 0;
}