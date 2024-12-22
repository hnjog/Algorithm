#include <string>
#include <vector>
#include<limits.h>
#include<queue>

using namespace std;

void setting(vector<vector<int>>& overs)
{
	overs[0] = { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 };
	overs[1] = { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 };
	overs[2] = { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 };
	overs[3] = { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 };
	overs[4] = { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 };
	overs[5] = { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 };
	overs[6] = { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 };
	overs[7] = { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 };
	overs[8] = { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 };
	overs[9] = { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 };
}

int dp[100001][10][10] = { 0 };

int dpCheck(const vector<vector<int>>& overs,const string& numbers, int leftPos,int rightPos, int nowStep,int nowCost)
{
	if (leftPos == rightPos)
		return INT_MAX / 2;

	if (dp[nowStep][leftPos][rightPos] != 0)
		return dp[nowStep][leftPos][rightPos];

	if (nowStep == numbers.size())
		return nowCost;

	int target = int(numbers[nowStep] - '0');
	int leftValue = overs[leftPos][target];
	int rightValue = overs[rightPos][target];

	int chooseLeft = leftValue + dpCheck(overs, numbers, target, rightPos, nowStep + 1,nowCost);
	int chooseRight = rightValue + dpCheck(overs, numbers, leftPos, target, nowStep + 1,nowCost);

	return dp[nowStep][leftPos][rightPos] = min(chooseLeft, chooseRight);
}

int solution(string numbers) {
	const int n = 10;
	vector<vector<int>> overs(n);
	setting(overs);

	return dpCheck(overs, numbers, 4, 6, 0,0);
}