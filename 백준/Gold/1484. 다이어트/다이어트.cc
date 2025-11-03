#include<iostream>
#include<vector>

using namespace std;

int GetValue(int a, int b)
{
	return (a + b) * (a - b);
}

int main()
{
	int g;
	cin >> g;

	int t1 = 2; // a
	int t2 = 1; // b
	vector<int> v;

	while (t1 > t2)
	{
		int vv = GetValue(t1, t2);
		if (vv == g)
		{
			v.push_back(t1);
			t1++;
			t2++;
			continue;
		}

		if (vv > g)
		{
			t2++;
		}
		else
		{
			t1++;
		}
	}

	if (v.size() > 0)
	{
		for (int i : v)
		{
			cout << i << '\n';
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}