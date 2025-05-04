#include<iostream>
#include<string>
#include<vector>

using namespace std;

void recur(char color, int nowy, int nowx, bool bOdd, vector<string>& map, vector<vector<bool>>& visited);

int dfs(vector<string>& map, bool bOdd)
{
	int count = 0;
	vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));

	int size = map.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (visited[i][j] == false)
			{
				count++;
				recur(map[i][j], i, j, bOdd, map, visited);
			}
		}
	}

	return count;
}

void recur(char color, int nowy, int nowx, bool bOdd, vector<string>& map, vector<vector<bool>>& visited)
{
	int size = visited.size();
	if (nowy < 0 || nowx < 0 ||
		nowy >= size || nowx >= size)
		return;

	if (visited[nowy][nowx] == true)
		return;

	if (bOdd == false &&
		map[nowy][nowx] != color)
		return;

	if (bOdd)
	{
		switch (color)
		{
		case 'R':
		case 'G':
		{
			if (map[nowy][nowx] == 'B')
				return;
		}
		break;
		default:
		{
			if (map[nowy][nowx] != color)
				return;
		}
		break;
		}
	}


	visited[nowy][nowx] = true;

	recur(color, nowy - 1, nowx, bOdd, map, visited);
	recur(color, nowy, nowx - 1, bOdd, map, visited);
	recur(color, nowy + 1, nowx, bOdd, map, visited);
	recur(color, nowy, nowx + 1, bOdd, map, visited);
}

int main()
{
	int n;
	cin >> n;
	vector<string> vec;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}

	cout << dfs(vec, false) << " " << dfs(vec, true);
}