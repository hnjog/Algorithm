#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct linfo
{
	int limitDay;
	int pay;
};

struct Compare
{
	bool operator()(const linfo& a, const linfo& b)
	{
		return a.pay > b.pay;
	}
};

int main()
{
	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	vector<linfo> vec;

	for (int i = 0; i < n; i++)
	{
		linfo l;
		cin >> l.pay >> l.limitDay;
		vec.push_back(l);
	}

	sort(vec.begin(), vec.end(), [](const linfo& a, const linfo& b) 
		{
			if (a.limitDay == b.limitDay)
				return a.pay > b.pay;

			return a.limitDay < b.limitDay;
		});

	int d = 0;
	int ans = 0;

	priority_queue<linfo, vector<linfo>, Compare> pq;

	for (int i = 0; i < n; i++)
	{
		int ld = vec[i].limitDay;
		int p = vec[i].pay;
		pq.push(vec[i]);
		ans += p;

		if (ld < pq.size())
		{
			ans -= pq.top().pay;
			pq.pop();
		}
	}

	cout << ans;
	
	return 0;
}