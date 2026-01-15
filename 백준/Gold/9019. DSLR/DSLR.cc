#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

const char ords[4] = { 'D','S', 'L', 'R' };

int Dfunc(int n)
{
	return (n * 2) % 10000;
}

int Sfunc(int n)
{
	n--;

	if (n < 0)
		return 9999;

	return n;
}

int Lfunc(int n)
{
	if (n < 1000)
		return n * 10;

	int v = n / 1000;

	int ret = (n - (v * 1000)) * 10 + v;

	return ret;
}

int Rfunc(int n)
{
	int v = n % 10;

	int ret = n / 10 + v * 1000;

	return ret;
}

struct infos
{
	int prev;
	int now;
};

void FindRoute(int start, int target)
{
	queue<infos> pq;

	pq.push({ -1,start });

	vector<bool> visit(10000, false);
	vector<pair<int,int>> prev(10000);

	visit[start] = true;
	prev[start] = { -1,-1 };

	while (true)
	{
		int prevV = pq.front().prev;
		int nowV = pq.front().now;
		pq.pop();

		if (nowV == target)
		{
			string ret = "";

			int idx = nowV;
			while (prev[idx].first != -1)
			{
				ret.push_back(ords[prev[idx].second]);
				idx = prev[idx].first;
			}

			reverse(ret.begin(), ret.end());

			cout << ret << '\n';

			return;
		}

		int nV = Dfunc(nowV);
		if (visit[nV] == false)
		{
			pq.push({ nowV,nV });
			visit[nV] = true;
			prev[nV] = { nowV,0 };
		}

		nV = Sfunc(nowV);
		if (visit[nV] == false)
		{
			pq.push({ nowV,nV });
			visit[nV] = true;
			prev[nV] = { nowV,1 };
		}

		nV = Lfunc(nowV);
		if (visit[nV] == false)
		{
			pq.push({ nowV,nV });
			visit[nV] = true;
			prev[nV] = { nowV,2 };
		}

		nV = Rfunc(nowV);
		if (visit[nV] == false)
		{
			pq.push({ nowV,nV });
			visit[nV] = true;
			prev[nV] = { nowV,3 };
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> orders(n);

	for (int i = 0; i < n; i++)
	{
		cin >> orders[i].first >> orders[i].second;
	}

	for (auto& p : orders)
	{
		FindRoute(p.first, p.second);
	}

	return 0;
}