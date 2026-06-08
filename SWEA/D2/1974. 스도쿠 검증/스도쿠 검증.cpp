#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool CheckRight(const vector<vector<int>>& maps)
{
	for (int i = 0; i < 9; i++)
	{
		unordered_set<int> countHo;
		for (int j = 0; j < 9; j++)
		{
			int val = maps[i][j];
			if (countHo.find(val) != countHo.end())
				return false;

			countHo.insert(val);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		unordered_set<int> countVe;
		for (int j = 0; j < 9; j++)
		{
			int val = maps[j][i];
			if (countVe.find(val) != countVe.end())
				return false;

			countVe.insert(val);
		}
	}

	vector<unordered_set<int>> countNine(9);

	for (int yi = 0; yi < 9; yi += 3)
	{
		for (int xi = 0; xi < 9; xi += 3)
		{
			unordered_set<int> countNine;
			for (int i = yi; i < yi + 3; i++)
			{
				for (int j = xi; j < xi + 3; j++)
				{
					int val = maps[i][j];
					if (countNine.find(val) != countNine.end())
						return false;

					countNine.insert(val);
				}
			}
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<int>> maps(9, vector<int>(9, 0));

		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> maps[i][j];

		int result = CheckRight(maps) ? 1 : 0;
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;
}