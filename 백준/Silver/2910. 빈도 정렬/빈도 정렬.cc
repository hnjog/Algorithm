#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;

	unordered_map<int, pair<int,int>> um;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (um.find(t) == um.end())
		{
			um[t].first = i;
			um[t].second = 1;
		}
		else
		{
			um[t].second++;
		}
	}

	struct tv
	{
		int v, count, idx;
	};

	vector<tv> vec;

	for (auto& p : um)
	{
		vec.push_back({ p.first,p.second.second,p.second.first });
	}

	sort(vec.begin(), vec.end(), []
	(tv& a, tv& b)
		{
			if (a.count == b.count)
				return a.idx < b.idx;
			return a.count > b.count;
		});

	int vs = vec.size();

	for (int i = 0; i < vs; i++)
	{
		for (int j = 0; j < vec[i].count; j++)
		{
			cout << vec[i].v << ' ';
		}
	}

	return 0;
}