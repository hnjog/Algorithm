#include <vector>

using namespace std;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
int N, M;

bool safe(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}

bool cant_move(vector<vector<int>>& board, int y, int x)
{
	for (int d = 0; d < 4; ++d)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (safe(ny, nx) && board[ny][nx])
			return false;
	}
	return true;
}

pair<bool, int> func(vector<vector<int>>& board, int y1, int x1, int y2, int x2)
{
	if (cant_move(board, y1, x1))
	{
		return { false, 0 }; // 움직일 수 없으면 패배
	}

	pair<bool, int> ret = { false, 0 };

	// 자신의 발판 있는 경우 => 없으면 바로 패배 리턴
	if (board[y1][x1])
	{
		int minT = 1e9, maxT = 0;
		for (int d = 0; d < 4; ++d)
		{
			int ny = y1 + dy[d];
			int nx = x1 + dx[d];

			if (safe(ny, nx) == false || board[ny][nx] == false)
				continue;

			board[y1][x1] = 0;
			auto result = func(board, y2, x2, ny, nx);
			bool win = result.first;
			int moveCount = result.second;

			board[y1][x1] = 1;

			if (win == false) // 상대가 질 경우 => 내가 이길 수 있는 경우의 수 : 최소 움직임으로 플레이
			{
				ret.first = true;
				minT = min(minT, moveCount);
			}
			else if (ret.first == false) // 내가 질 경우 : 최대 움직임으로 플레이
			{
				maxT = max(maxT, moveCount);
			}
		}

		ret.second = ret.first ? minT + 1 : maxT + 1;
	}

	return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	N = board.size(), M = board[0].size();
	return func(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}