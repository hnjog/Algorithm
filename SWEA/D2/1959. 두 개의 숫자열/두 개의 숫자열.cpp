#include<iostream>
#include<vector>

using namespace std;

int GetBestV(const vector<int>& longArr, const vector<int>& shortArr)
{
	int ls = longArr.size();
	int ss = shortArr.size();

	int best = 0;

	for (int i = 0; i <= ls - ss; i++)
	{
		int t = 0;
		for (int j = 0; j < ss; j++)
		{
			t += (longArr[i + j] * shortArr[j]);
		}

		best = max(best, t);
	}

	return best;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		vector<int> narr(n), marr(m);

		for (int i = 0; i < n; i++)
			cin >> narr[i];

		for (int i = 0; i < m; i++)
			cin >> marr[i];

		int best = 0;
		if (n < m)
			best = GetBestV(marr, narr);
		else if(m < n)
			best = GetBestV(narr, marr);
		else
		{
			for (int i = 0; i < n; i++)
				best += (narr[i] * marr[i]);
		}

		cout << '#' << test_case << ' ' << best << '\n';
	}
	return 0;
}