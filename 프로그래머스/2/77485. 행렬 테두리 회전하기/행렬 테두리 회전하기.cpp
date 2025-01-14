#include <vector>
#include <limits.h>

using namespace std;

int rotateBorder(vector<vector<int>>& matrix, vector<int>& query) {
	int r1 = query[0] - 1;
	int c1 = query[1] - 1;
	int r2 = query[2] - 1;
	int c2 = query[3] - 1;

	vector<int> border;
	int ret = INT_MAX;

	for (int j = c1; j <= c2; j++)
	{
		if (ret > matrix[r1][j])
			ret = matrix[r1][j];
		border.push_back(matrix[r1][j]);
	}

	for (int i = r1 + 1; i <= r2; i++)
	{
		if (ret > matrix[i][c2])
			ret = matrix[i][c2];
		border.push_back(matrix[i][c2]);
	}

	if (r1 < r2)
	{
		for (int j = c2 - 1; j >= c1; j--)
		{
			if (ret > matrix[r2][j])
				ret = matrix[r2][j];
			border.push_back(matrix[r2][j]);
		}
	}

	if (c1 < c2)
	{
		for (int i = r2 - 1; i > r1; i--)
		{
			if (ret > matrix[i][c1])
				ret = matrix[i][c1];
			border.push_back(matrix[i][c1]);
		}
	}

	int n = border.size();
	int last = border.back();
	for (int i = n - 1; i > 0; i--) 
	{
		border[i] = border[i - 1];
	}
	border[0] = last;

	int idx = 0;

	for (int j = c1; j <= c2; j++) 
	{
		matrix[r1][j] = border[idx++];
	}

	for (int i = r1 + 1; i <= r2; i++) 
	{
		matrix[i][c2] = border[idx++];
	}

	if (r1 < r2) 
	{
		for (int j = c2 - 1; j >= c1; j--) 
		{
			matrix[r2][j] = border[idx++];
		}
	}

	if (c1 < c2) 
	{
		for (int i = r2 - 1; i > r1; i--) 
		{
			matrix[i][c1] = border[idx++];
		}
	}

	return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;

	vector<vector<int>> arr(rows, vector<int>(columns, 0));
	int idx = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr[i][j] = idx;
			idx++;
		}
	}

	for (auto& q : queries)
	{
		answer.push_back(rotateBorder(arr, q));
	}

	return answer;
}
