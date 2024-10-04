#include <string>
#include <vector>

using namespace std;

int check(vector<string>& board)
{
	int result = 0;

	int bSize1 = board.size();
	int bSize2 = board[0].size();

	// 이게 true로 되어 있는 녀석들 나중에 싹 'x'(소문자)로 바꿔주기
	vector<vector<bool>> checker(bSize1,vector<bool>(bSize2,false));

	for (int y = 0; y < bSize1 - 1; y++)
	{
		for (int x = 0; x < bSize2 - 1; x++)
		{
			// 2x2
			char now = board[y][x];
			if (now == 'x')
				continue;

			if (now == board[y][x + 1] &&
				now == board[y + 1][x] &&
				now == board[y + 1][x + 1])
			{
				checker[y][x] = true;
				checker[y][x + 1] = true;
				checker[y + 1][x] = true;
				checker[y + 1][x + 1] = true;
			}
		}
	}

	for (int i = 0; i < bSize1; i++)
	{
		for (int j = 0; j < bSize2; j++)
		{
			if (checker[i][j])
			{
				board[i][j] = 'x';
				result++;
			}
		}
	}

	int c = 0;

	return result;
}

void sortingFunc(vector<string>& board)
{
	// 'x' 되어 있는 녀석들을 그 위에 2칸들과 바꿔줄 예정
	int bSize1 = board.size();
	int bSize2 = board[0].size();

	for (int y = bSize1 - 1; y >= 1; y--)
	{
		for (int x = 0; x < bSize2; x++)
		{
			if (board[y][x] == 'x')
			{
				int idx = 0;
				bool isFind = false;
				for (int i = y - 1; i >= 0; i--)
				{
					if (board[i][x] != 'x')
					{
						idx = i;
						isFind = true;
						break;
					}
				}
				if (isFind)
					swap(board[y][x], board[idx][x]);
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	
	while (true)
	{
		auto temp = board;
		int result = check(board);

		if (result == 0)
		{
			break;
		}
		else
		{
			answer += result;
			sortingFunc(board);
		}
	}

	return answer;
}