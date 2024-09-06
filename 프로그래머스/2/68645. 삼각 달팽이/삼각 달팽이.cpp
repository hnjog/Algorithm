#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	
	int count = 0;
	for (int i = 1; i <= n; i++)
		count += i;

	int dx[3] = { 0,1,-1 };
	int dy[3] = { 1,0,-1 };
	vector<vector<int>> map(n, vector<int>(n, 0));

	int dir = 0;
	int value = 1;
	int x = 0;
	int y = 0;

	while (true)
	{
		map[y][x] = value;

		if (value >= count)
			break;

		int nextX = x + dx[dir];
		int nextY = y + dy[dir];

		if (nextX >= n || nextY >= n ||
			nextX < 0 || nextY < 0 ||
			map[nextY][nextX] != 0)
		{
			dir++;
			if (dir >= 3)
				dir = 0;

			continue;
		}

		x = nextX;
		y = nextY;

		value++;
	}

	for (int i = 0; i < n; i++) // y
	{
		for (int j = 0; j < n; j++) // x
		{
			if (map[i][j] == 0)
				break;

			answer.push_back(map[i][j]);
		}
	}

	return answer;
}