#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool IsString(const vector<string>& maps, int len, int y, int x, bool bHorizon)
{
	int mSize = maps.size();

	if ((bHorizon && x + len > 100) ||
		(bHorizon == false && y + len > 100))
	{
		return false;
	}

	for (int i = 0; i <= len / 2; i++)
	{
		if (bHorizon)
		{
			if (maps[y][x + i] != maps[y][x + len - 1 - i])
			{
				return false;
			}
		}
		else
		{
			if (maps[y + i][x] != maps[y + len - 1 - i][x])
			{
				return false;
			}
		}
	}

	return true;
}

int GetFindLenStr(const vector<string>& maps, int len)
{
	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (IsString(maps, len, i, j, true))
				count++;

			if (IsString(maps, len, i, j, false))
				count++;
		}
	}

	return count;
}

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		int n;
		cin >> n;

		vector<string> maps(100);

		for (int i = 0; i < 100; i++)
			cin >> maps[i];

		int ret = 0;
		for (int i = 100; i > 0; i--)
		{
			if (GetFindLenStr(maps, i))
			{
				ret = i;
				break;
			}
		}

		cout << '#' << n << ' ' << ret << '\n';
	}
	return 0;
}