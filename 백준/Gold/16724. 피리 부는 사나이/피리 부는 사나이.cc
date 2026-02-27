#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef pair<int, int> pii;

pii FindParent(vector<vector<pii>>& pv, pii& p)
{
	if (pv[p.first][p.second] == p)
		return p;

	return pv[p.first][p.second] = FindParent(pv, pv[p.first][p.second]);
}

bool Union(vector<vector<pii>>& pv, pii& a, pii& b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a.first][a.second] = b;

	return true;
}

pii GetNPos(char dir, pii& now)
{
	pii next = now;

	switch (dir)
	{
	case 'D':
	{
		next.first += 1;
	}
		break;
	case 'U':
	{
		next.first -= 1;
	}
	break;
	case 'R':
	{
		next.second += 1;
	}
	break;
	case 'L':
	{
		next.second -= 1;
	}
	break;
	default:
		break;
	}

	return next;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<pii>> pv(n,vector<pii>(m));
	vector<vector<char>> map(n,vector<char>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			pv[i][j] = { i,j };
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (pv[i][j].first == i &&
				pv[i][j].second == j)
			{
				pii nPos = GetNPos(map[i][j], pv[i][j]);
				Union(pv, pv[i][j], nPos);
			}
		}
	}

	set<pii> sp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			pii p = { i,j };
			p = FindParent(pv, p);
			sp.insert(p);
		}
	}

	cout << sp.size();

	return 0;
}