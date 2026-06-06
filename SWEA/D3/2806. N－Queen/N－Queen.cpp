#include<iostream>
#include<vector>

using namespace std;

bool IsCanPlaceQueen(vector<vector<bool>>& board, int nowY, int nowX)
{
	if (board[nowY][nowX])
		return false;
	int n = board.size();
	// 위쪽의 4 방향 검사
	for (int i = 0; i < n; i++)
	{
		if (board[nowY][i])
			return false;
		
		if (board[i][nowX])
			return false;

		if (nowY - i >= 0 &&
			nowX - i >= 0 &&
			board[nowY - i][nowX - i])
			return false;

		if (nowY - i >= 0 &&
			nowX + i < n &&
			board[nowY - i][nowX + i])
			return false;
	}

	return true;
}

int Recur(vector<vector<bool>>& board, int remain, int nowY)
{
	if (remain == 0)
		return 1;

	int count = 0;
	int n = board.size();
	for (int i = 0; i < n; i++)
	{
		if (board[nowY][i])
			continue;

		if (IsCanPlaceQueen(board, nowY, i) == false)
			continue;

		board[nowY][i] = true;
		count += Recur(board, remain - 1, nowY + 1);
		board[nowY][i] = false;
	}

	return count;
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

		vector<vector<bool>> boards(n, vector<bool>(n, false));

		cout << '#' << test_case << ' ' << Recur(boards, n, 0) << '\n';
	}
	return 0;
}