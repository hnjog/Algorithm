#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

int FindParent(vector<pair<int, string>>& pv, int x)
{
	if (pv[x].first == x)
		return x;

	return pv[x].first = FindParent(pv, pv[x].first);
}

bool Union(vector<pair<int, string>>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);
	if (a == b)
		return false;

	pv[a].first = b;

	return true;
}

const string ks = "Kingdom of ";

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<pair<int,string>> pv(n);
	unordered_map<string, int> um;
	
	for (int i = 0; i < n; i++)
	{
		pv[i].first = i;

		string str1,str2,str3;
		cin >> str1 >> str2 >> str3;
		
		pv[i].second = str3;
		um[str3] = i;
	}

	for (int i = 0; i < m; i++)
	{
		string str1, str2, str3, str4, str5;
		cin >> str1 >> str2 >> str3 >> str4 >> str5;

		char c = ',';
		size_t p1 = str3.find(c);
		size_t p2 = str5.find(c);
		string a(str3.begin(), str3.begin() + p1);
		string b(str5.begin(), str5.begin() + p2);

		char ret = str5.back();

		int a1 = um[a];
		int b1 = um[b];

		if (ret == '1')
		{
			if (Union(pv, b1, a1) == false)
			{
				pv[b1].first = a1;
				pv[a1].first = a1;
			}
		}
		else
		{
			if (Union(pv, a1, b1) == false)
			{
				pv[a1].first = b1;
				pv[b1].first = b1;
			}
		}
	}

	vector<string> results;

	for (int i = 0; i < n; i++)
	{
		if (FindParent(pv,i) == i)
		{
			results.push_back(ks + pv[i].second);
		}
	}

	sort(results.begin(), results.end());

	cout << results.size() << '\n';

	for (auto& s : results)
	{
		cout << s << '\n';
	}
	return 0;
}