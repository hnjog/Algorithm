#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

int FindParent(vector<pii>& pv, int x)
{
	if (pv[x].first == x)
		return x;

	return pv[x].first = FindParent(pv, pv[x].first);
}

bool Unions(vector<pii>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a].first = b;
	pv[b].second += pv[a].second;
	pv[a].second = 0;

	return true;
}

int GetValue(vector<pii>& pv, int x)
{
	int p = FindParent(pv, x);
	return pv[p].second;
}

int main()
{
	/*
		분리집합이지만 '개수'를 세는데 유의할 것
		유의할점?

		이거 vector 개수를 100만개까지 할 수 있나...??
	*/

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int mv = 1000001;

	vector<pii> pv(mv);
	for (int i = 0; i < mv; i++)
	{
		pv[i].first = i;
		pv[i].second = 1;
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;

		if (c == 'I')
		{
			int a, b;
			cin >> a >> b;
			Unions(pv, a, b);
		}
		else if (c == 'Q')
		{
			int a;
			cin >> a;
			cout << GetValue(pv, a)<< '\n';
		}
	}

	return 0;
}