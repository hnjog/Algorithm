#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct infos
{
	int u, v, s;
};

int find(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = find(pv, pv[x]);
}

bool Union(vector<int>& pv, int a, int b)
{
	a = find(pv, a);
	b = find(pv, b);

	if (a != b)
	{
		pv[a] = b;
		return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;

	vector<int> pv(n);

	for (int i = 0; i < n; i++)
		pv[i] = i;

	vector<infos> iv(m);

	for (int i = 0; i < m; i++)
	{
		cin >> iv[i].u >> iv[i].v >> iv[i].s;
		iv[i].u--;
		iv[i].v--;
	}

	sort(iv.begin(), iv.end(), [](const infos& a, const infos& b) {
		return a.s < b.s;
		});

	long sum = 0;

	long c = n;
	int ps = 1;

	for (int i = 0; i < m; i++)
	{
		long bv = c * (iv[i].s - ps);
		sum += bv;
		ps = iv[i].s;

		if (Union(pv, iv[i].u, iv[i].v))
		{
			c--;
		}
	}

	sum += c * (t - ps + 1);

	cout << sum;

	return 0;
}