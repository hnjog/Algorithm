#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int dirY[4] = { 0,1,1,1 };
const int dirX[4] = { 1,-1,0,1 };

bool CheckDir(vector<string>& maps, int y,int x)
{
	int n = maps.size();

	if (maps[y][x] == '.')
		return false;

	vector<bool> dirCheck(4, true);

	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (dirCheck[j] == false)
				continue;

			int ny = dirY[j] * i + y;
			int nx = dirX[j] * i + x;

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= n)
			{
				dirCheck[j] = false;
				continue;
			}

			if (maps[ny][nx] == '.')
			{
				dirCheck[j] = false;
			}
		}
	}

	for (bool check : dirCheck)
	{
		if (check)
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		vector<string> strs(n);

		for (int i = 0; i < n; i++)
		{
			cin >> strs[i];
		}

		bool check = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (strs[i][j] == 'o')
				{
					if (CheckDir(strs, i, j))
					{
						check = true;
						break;
					}
				}
			}
			if (check)
				break;
		}

		cout << '#' << test_case << ' ';
		if (check)
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
	return 0;
}