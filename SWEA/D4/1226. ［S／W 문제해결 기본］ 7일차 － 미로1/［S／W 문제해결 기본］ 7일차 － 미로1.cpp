#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct pos
{
	int y, x;
};

int FindWay(const vector<vector<int>>& maps, pos& start, pos& end)
{
	const int dirY[4] = { 0,-1,0,1 };
	const int dirX[4] = { -1,0,1,0 };

	queue<pos> q;
	q.push(start);

	vector<vector<bool>> visited(16, vector<bool>(16,false));

	while (q.empty() == false)
	{
		int nowy = q.front().y;
		int nowx = q.front().x;
		q.pop();

		if (nowy < 0 || nowy >= 16 ||
			nowx < 0 || nowx >= 16)
			continue;

		if (maps[nowy][nowx] == 3)
			return 1;

		if (maps[nowy][nowx] == 1)
			continue;

		if (visited[nowy][nowx])
			continue;

		visited[nowy][nowx] = true;

		for (int i = 0; i < 4; i++)
		{
			q.push({ nowy + dirY[i],nowx + dirX[i] });
		}
	}

	return 0;
}

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		int n;
		cin >> n;

		vector<vector<int>> maps(16, vector<int>(16));

		pos start, end;
		for (int i = 0; i < 16; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < 16; j++)
			{
				maps[i][j] = str[j] - '0';
				if (maps[i][j] == 2)
				{
					start.y = i;
					start.x = j;
				}
				else if (maps[i][j] == 3)
				{
					end.y = i;
					end.x = j;
				}
			}
		}

		int ret = FindWay(maps,start,end);

		cout << '#' << n << ' ' << ret << '\n';
	}
	return 0;
}