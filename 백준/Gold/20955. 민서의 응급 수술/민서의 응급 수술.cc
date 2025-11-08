#include<iostream>
#include<vector>

using namespace std;

int FindParent(vector<int>& pv, int x)
{
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

	pv[a] = b;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	vector<int> pv(n);
	for (int i = 0; i < n; i++)
		pv[i] = i;

	int ans = n - 1;

	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		if (Union(pv, t1, t2))
			ans--;
		else
			ans++;
	}

	cout << ans;

	return 0;
}