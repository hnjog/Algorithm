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
	int n;
	cin >> n;
	vector<int> pv(n);
	for (int i = 0; i < n; i++)
		pv[i] = i;

	for (int i = 0; i < n - 2; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		Union(pv, t1, t2);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Union(pv, i, j))
			{
				cout << i + 1 << " " << j + 1;
				return 0;
			}
		}
	}

	return 0;
}