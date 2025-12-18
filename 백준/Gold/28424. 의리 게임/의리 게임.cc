#include<iostream>
#include<vector>

using namespace std;

int FindParent(vector<int>& pv, vector<int>& nv, vector<int>& cv, int now)
{
	// 가장 끝
	if (pv[now] == now)
		return now;

	int v = pv[now];

	// 아직 술 마실수 있음
	if (nv[v] < cv[v])
		return v;

	return pv[now] = FindParent(pv, nv, cv, v);
}

void drink(int idx, int lit, vector<int>& pv, vector<int>& nv, vector<int>& cv)
{
	if (idx >= pv.size())
		return;

	int canDrink = cv[idx] - nv[idx];

	// 전부 마실 수 있음
	if (lit <= canDrink)
	{
		nv[idx] += lit;
		return;
	}

	// 전부 마실 수 없는 상태
	nv[idx] = cv[idx];
	int remain = lit - canDrink;

	int n = FindParent(pv, nv, cv, idx);

	if (n == idx)
		return;

	drink(n,remain, pv, nv, cv);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	// 각 노드들은 술을 다음으로 넘길 녀석을 인덱스로 지정
	vector<int> pv(n);
	for (int i = 0; i < n - 1; i++)
	{
		pv[i] = i + 1;
	}

	pv[n - 1] = n - 1;

	vector<int> nv(n), cv(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cv[i];
	}

	for (int i = 0; i < q; i++)
	{
		int o;
		cin >> o;
		if (o == 1)
		{
			int id, m;
			cin >> id >> m;
			id--;
			drink(id, m, pv, nv, cv);
		}
		else
		{
			int id;
			cin >> id;
			id--;
			cout << nv[id] << '\n';
		}
	}

	return 0;
}