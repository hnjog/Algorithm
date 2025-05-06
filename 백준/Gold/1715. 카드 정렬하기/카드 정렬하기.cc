#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		pq.push(t);
	}

	int sum = 0;

	while (pq.size() >= 2)
	{
		int i1 = pq.top();
		pq.pop();
		int i2 = pq.top();
		pq.pop();

		int i3 = i1 + i2;
		sum += i3;
		pq.push(i3);
	}

	cout << sum;
}