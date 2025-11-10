#include<iostream>
#include<vector>

using namespace std;

int FindParent(vector<int>& pv, int x)
{
	if (x == -1)
		return x;

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

	if (a == -1 ||
		b == -1)
	{
		return false;
	}

	pv[a] = b;
	return true;
}

int main()
{
	int idx = 1;

	while (true)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 &&
			m == 0)
		{
			break;
		}

		vector<int> pv(n);
		for (int i = 0; i < n; i++)
			pv[i] = i;

		for (int i = 0; i < m; i++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			t1--;
			t2--;
			if (Union(pv,t1,t2) == false)
			{
				int x1 = FindParent(pv, t1);
				int x2 = FindParent(pv, t2);
				// 사이클이 발생한 녀석들
				if(x1 != -1)
					pv[x1] = -1;

				if(x2 != -1)
					pv[x2] = -1;
			}
		}

		for (int i = 0; i < n; i++)
			FindParent(pv, i);

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			if (pv[i] == i)
				ans++;
		}

		cout << "Case " << idx << ": ";

		if (ans >= 2)
			cout << "A forest of " << ans << " trees." << '\n';
		else if (ans == 1)
			cout << "There is one tree." << '\n';
		else
			cout << "No trees." << '\n';

		idx++;
	}

	return 0;
}