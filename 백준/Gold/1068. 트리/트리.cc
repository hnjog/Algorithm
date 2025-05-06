#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct node
{
	int v;
	int parent;
};

int dfs(unordered_map<int, vector<node>>& maps, int now)
{
	if (maps.find(now) == maps.end())
		return 1;

	int ret = 0;

	for (node& v : maps[now])
	{
		ret += dfs(maps, v.v);
	}


	return ret;
}

int getFindParent(unordered_map<int, vector<node>>& maps,int now, int target)
{
	int ret = 0;

	for (node& v : maps[now])
	{
		if (v.v == target)
			return now;

		ret += getFindParent(maps, v.v,target);
	}

	return ret;
}

int main()
{
	int n;
	cin >> n;

	unordered_map<int, vector<node>> maps;
	unordered_set<int> leafs;

	int root = 0;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;

		if (p == -1)
		{
			root = i;
			continue;
		}

		maps[p].push_back({ i,p });
	}

	for (int i = 0; i < n; i++)
	{
		if (i == root)
			continue;

		if (maps.find(i) == maps.end())
		{
			leafs.insert(i);
		}
	}

	int d;
	cin >> d;
	if (d == root)
	{
		cout << 0;
		return 0;
	}

	if (leafs.find(d) == leafs.end())
	{
		int c = leafs.size() - dfs(maps, d);
		if (c != 0)
			cout << c;
		else
			cout << 1;
	}
	else
	{
		// leaf를 삭제하려 한다
		int c = getFindParent(maps, root, d);
		if (maps[c].size() == 1)
			cout << leafs.size();
		else
			cout << leafs.size() - 1;
	}

}