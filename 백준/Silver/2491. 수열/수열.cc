#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vec.push_back(t);
	}

	stack<pii> minq, maxq;
	int minL = 0, maxL = 0;

	for (int i = 0; i < n; i++)
	{
		int nowV = vec[i];

		// min
		if (minq.empty())
		{
			minq.push(make_pair(nowV, i));
		}
		else
		{
			int tV = minq.top().first;
			// minq는 연속 내림 검사이므로 tv가 현재 값보다 작은 경우 빼준다
			if (tV < nowV)
			{
				minL = max(minL, int(minq.size()));
				while (minq.empty() == false)
					minq.pop();
			}
			
			minq.push(make_pair(nowV, i));
		}

		if (maxq.empty())
		{
			maxq.push(make_pair(nowV, i));
		}
		else
		{
			int tv = maxq.top().first;

			if (tv > nowV)
			{
				maxL = max(maxL, int(maxq.size()));
				while (maxq.empty() == false)
					maxq.pop();
			}
			
			maxq.push(make_pair(nowV, i));
		}

	}

	minL = max(minL, int(minq.size()));
	maxL = max(maxL, int(maxq.size()));

	cout << max(minL, maxL);

}