#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

string FindParent(unordered_map<string, pair<string, int>>& fmap, string x)
{
	if (fmap[x].first == x)
		return x;

	return fmap[x].first = FindParent(fmap, fmap[x].first);
}

bool Union(unordered_map<string, pair<string, int>>& fmap, string a,string b)
{
	a = FindParent(fmap, a);
	b = FindParent(fmap, b);

	if (a == b)
		return false;

	fmap[a].first = b;
	fmap[b].second += fmap[a].second;
	fmap[a].second = 1;
	return true;
}

int main()
{
	
	int t;
	cin >> t;
	while (t > 0)
	{
		int f;
		cin >> f;

		unordered_map<string, pair<string,int>> fmap;

		for (int i = 0; i < f; i++)
		{
			string f1, f2;
			cin >> f1 >> f2;
			if (fmap.find(f1) == fmap.end())
				fmap[f1] = make_pair(f1,1);
			if (fmap.find(f2) == fmap.end())
				fmap[f2] = make_pair(f2, 1);

			Union(fmap, f1, f2);
			cout << fmap[FindParent(fmap, f1)].second << '\n';
		}

		t--;
	}

	return 0;
}