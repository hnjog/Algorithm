#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

void Dfs(const vector<vector<char>>& maps, int startY, int startX, string& temp, unordered_set<string>& us)
{
	if (temp.size() >= 7)
	{
		us.insert(temp);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = dirY[i] + startY;
		int nx = dirX[i] + startX;

		if (ny < 0 || ny >= 4 ||
			nx < 0 || nx >= 4)
			continue;

		temp.push_back(maps[ny][nx]);
		Dfs(maps, ny, nx, temp, us);
		temp.pop_back();
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<char>> maps(4, vector<char>(4));

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> maps[i][j];

		unordered_set<string> us;

		string temp = "";

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				temp.push_back(maps[i][j]);
				Dfs(maps, i, j, temp, us);
				temp.pop_back();
			}
		}

		cout << '#' << test_case << ' ' << us.size() << '\n';
	}
	return 0;
}