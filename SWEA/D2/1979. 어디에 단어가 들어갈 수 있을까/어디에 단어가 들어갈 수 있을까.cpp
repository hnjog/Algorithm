#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

void Setting(const vector<vector<int>>& maps, vector<vector<pii>>& vals, int nowY,int nowX)
{
	int n = maps.size();

	if (maps[nowY][nowX] == 0)
		return;

	if (vals[nowY][nowX].first != -1 &&
		vals[nowY][nowX].second != -1)
		return;

	if (vals[nowY][nowX].first == -1)
	{
		for (int i = nowY; i < n; i++)
		{
			if (maps[i][nowX] == 0)
				break;

			vals[i][nowX].first = 0;
			vals[nowY][nowX].first++;
		}
	}

	if (vals[nowY][nowX].second == -1)
	{
		vals[nowY][nowX].second = 0;
		for (int i = nowX; i < n; i++)
		{
			if (maps[nowY][i] == 0)
				break;

			vals[nowY][i].second = 0;
			vals[nowY][nowX].second++;
		}
	}
}

void Check(const vector<vector<int>>& maps, vector<vector<pii>>& vals)
{
	int n = maps.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] == 1)
			{
				Setting(maps, vals, i, j);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		cin >> n >> k;

		vector<vector<int>> maps(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> maps[i][j];

		vector<vector<pii>> vals(n, vector<pii>(n, {-1,-1}));

		Check(maps, vals);

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (vals[i][j].first == k)
					count++;
				if (vals[i][j].second == k)
					count++;
			}
		}

		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;
}