#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int find(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = find(pv, pv[x]);
}

void Union(vector<int>& pv, int a, int b)
{
	a = find(pv, a);
	b = find(pv, b);

	if (a != b)
	{
		pv[a] = b;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> pv(n);
	vector<vector<int>> enemies(n, vector<int>());

	for (int i = 0; i < n; i++)
	{
		pv[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		char c;
		int a, b;
		cin >> c >> a >> b;
		a--;
		b--;

		if (c == 'F')
		{
			Union(pv, a, b);
		}
		else
		{
			enemies[a].push_back(b);

			for (int i = 0; i < enemies[a].size() - 1; i++)
			{
				Union(pv, enemies[a][i], enemies[a][i + 1]);
			}

			enemies[b].push_back(a);

			for (int i = 0; i < enemies[b].size() - 1; i++)
			{
				Union(pv, enemies[b][i], enemies[b][i + 1]);
			}
		}
	}

	unordered_set<int> us;
	
	for (int i = 0; i < n; i++)
	{
		us.insert(find(pv, i));
	}

	cout << us.size();

	return 0;
}