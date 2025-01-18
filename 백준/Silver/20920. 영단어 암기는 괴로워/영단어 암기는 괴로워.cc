#include<string>
#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct info
{
	string str;
	int sSize;
	int freq;
};

struct Compare
{
	bool operator()(const info& a, const info& b)
	{
		if (a.freq == b.freq)
		{
			if (a.sSize == b.sSize)
			{
				return a.str > b.str;
			}

			return a.sSize < b.sSize;
		}

		return a.freq < b.freq;
	}
};

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map<string, int> ma;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int ss = s.size();
		if (ss >= m)
		{
			ma[s]++;
		}
	}

	priority_queue<info, vector<info>, Compare> pq;

	for (auto& p : ma)
	{
		info i;
		i.str = p.first;
		i.sSize = i.str.size();
		i.freq = p.second;

		pq.push(i);
	}

	while (pq.empty() == false)
	{
		cout << pq.top().str << '\n';
		pq.pop();
	}
}