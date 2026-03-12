#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int nv;
	cin >> nv;

	priority_queue<int> pq;

	for (int i = 1; i < n; i++)
	{
		int t;
		cin >> t;
		pq.push(t);
	}

	int c = 0;

	while (pq.empty() == false &&
		nv <= pq.top())
	{
		c++;
		nv++;
		
		int v = pq.top();
		pq.pop();
		v--;
		pq.push(v);
	}

	cout << c;

	return 0;
}