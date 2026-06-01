#include <string>
#include <vector>
#include <queue>

using namespace std;

bool Check2x2(int nowY, int nowX, vector<string>& board)
{
	int m = board.size();
	int n = board[0].size();

	if (nowY + 1 >= m ||
		nowX + 1 >= n)
		return false;

	char start = board[nowY][nowX];

	if (start == ' ')
		return false;

	for (int i = nowY; i < nowY + 2; i++)
	{
		for (int j = nowX; j < nowX + 2; j++)
		{
			if (board[i][j] != start)
				return false;
		}
	}

	return true;
}

int TurnDestroy(vector<string>& board)
{
	int m = board.size();
	int n = board[0].size();
	vector<vector<bool>> checkBoard(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Check2x2(i, j, board))
			{
				checkBoard[i][j] = true;
				checkBoard[i + 1][j] = true;
				checkBoard[i][j + 1] = true;
				checkBoard[i + 1][j + 1] = true;
			}
		}
	}

	int count = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (checkBoard[i][j])
			{
				count++;
				board[i][j] = ' ';
			}
		}
	}

	return count;
}

void TurnSwap(vector<string>& board)
{
	int m = board.size();
	int n = board[0].size();

	for (int i = 0; i < n; i++)
	{
		queue<char> st;
		for (int j = 0; j < m; j++)
		{
			if (board[j][i] != ' ')
			{
				st.push(board[j][i]);
				board[j][i] = ' ';
			}
		}

		while (st.empty() == false)
		{
			board[m - st.size()][i] = st.front();
			st.pop();
		}
	}
}

int solution(int m, int n, vector<string> board)
{
	int answer = 0;

	while (true)
	{
		int val = TurnDestroy(board);

		if (val == 0)
			break;

		answer += val;
		TurnSwap(board);
	}

	return answer;
}