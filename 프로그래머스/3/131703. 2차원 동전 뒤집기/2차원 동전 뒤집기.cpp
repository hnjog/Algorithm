#include <limits.h>
#include <vector>

using namespace std;

int bSize = 0;

// 해당하는 열 중, 1과 0의 개수가 같거나 서로 반대인 경우만
// 열을 뒤집거나 뒤집지 않는다
// 그 외에는 뒤집어도 의미가 없음

void flipRow(vector<vector<int>>& beginning, int t)
{
	int limitx = beginning[0].size();
	for (int i = 0; i < limitx; i++)
	{
		if (beginning[t][i] == 0)
			beginning[t][i] = 1;
		else
			beginning[t][i] = 0;
	}
}

int checkColumnCount(vector<vector<int>>& beginning, vector<vector<int>>& target, int t)
{
	int count = 0;
	int limity = beginning.size();
	for (int i = 0; i < limity; i++)
	{
		if (beginning[i][t] == target[i][t])
			count++;
	}

	// 뒤집어야 함
	if (count == 0)
		return 0;

	// 조건에 맞는 경우는 냅둔다
	if (count == limity)
		return 1;

	// 이건 딱히 뒤집어서 득되지 않음
	return -1;
}

void isCheck(vector<vector<int>>& beginning, vector<vector<int>>& target, int nowCount, int& answer, int row)
{
	if (row == bSize)
	{
		for (int i = 0; i < beginning[0].size(); i++)
		{
			int rCount = checkColumnCount(beginning, target, i);
			if (rCount == -1)
				return;

			if (rCount == 0)
				nowCount++;
		}

		if (answer > nowCount)
			answer = nowCount;

		return;
	}

	flipRow(beginning, row);
	isCheck(beginning, target, nowCount + 1, answer, row + 1);
	flipRow(beginning, row);
	isCheck(beginning, target, nowCount, answer, row + 1);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
	int answer = INT_MAX;
	bSize = beginning.size();
	isCheck(beginning, target, 0, answer, 0);

	if (answer == INT_MAX)
		return -1;

	return answer;
}