#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int FindParent(vector<int>& pv, int x)
{
	if (pv[x] == -1)
		return -1;

	if (pv[x] == x)
		return x;

	return pv[x] = FindParent(pv, pv[x]);
}

bool Union(vector<int>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);
	if (a == b)
		return false;

	if (a == -1)
		pv[b] = -1;
	else if (b == -1)
		pv[a] = -1;
	else
		pv[a] = b;

	return true;
}


int main()
{
	int n, m;
	cin >> n >> m;

	int r;
	cin >> r;

	unordered_set<int> realKnowns;

	for (int i = 0; i < r; i++)
	{
		int t;
		cin >> t;
		realKnowns.insert(t - 1);
	}

	vector<int> partyPeoples(n, 0);
	for (int i = 0; i < n; i++)
	{
		partyPeoples[i] = i;
		if (realKnowns.find(i) != realKnowns.end())
			partyPeoples[i] = -1;
	}

	vector<vector<int>> ttv;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;

		vector<int> tv;
		for (int j = 0; j < t; j++)
		{
			int t2;
			cin >> t2;
			t2--;
			tv.push_back(t2);
		}

		for (int j = 0; j < t; j++)
		{
			for (int k = j + 1; k < t; k++)
			{
				Union(partyPeoples, tv[j], tv[k]);
			}
		}

		ttv.push_back(tv);
	}

	int ans = m;
	for (auto& tv : ttv)
	{
		bool bCan = true;

		for (int i : tv)
		{
			if (FindParent(partyPeoples, i) == -1)
			{
				bCan = false;
				break;
			}
		}

		if (bCan == false)
			ans--;
	}
	cout << ans;

	return 0;
}