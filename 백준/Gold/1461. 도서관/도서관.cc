#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	priority_queue<int, vector<int>, greater<int>> mq;
	priority_queue<int> pq;

	int bv = 0;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;

		if (bv < abs(t))
			bv = abs(t);

		t *= 2;

		if (t < 0)
			mq.push(t);
		else
			pq.push(t);

	}

	int v = 0;
	int mv = m - 1;

	while (pq.empty() == false)
	{
		int tv = pq.top();
		pq.pop();
		v += tv;

		for (int i = 0; i < mv; i++)
			if(pq.empty() == false)
				pq.pop();
	}
	
	while (mq.empty() == false)
	{
		int tv = mq.top();
		mq.pop();
		v -= tv;

		for (int i = 0; i < mv; i++)
			if (mq.empty() == false)
				mq.pop();
	}

	cout << v - bv;
	return 0;
}