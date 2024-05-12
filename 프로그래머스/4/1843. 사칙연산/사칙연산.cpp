#include <vector>
#include <string>
#include <climits> // INT_MIN, INT_MAX를 위함
using namespace std;

pair<int, int> calcMaxMinResult(vector<int>& nums, vector<char>& ops, int start, int end, vector<vector<pair<int, int>>>& dp) 
{
	// 최대값, 최소값 모두 자기 자신
	if (start == end)
		return { nums[start], nums[start] }; 

	if (dp[start][end].first != INT_MIN)
		return dp[start][end];

	int maxResult = INT_MIN;
	int minResult = INT_MAX;

	for (int i = start; i < end; ++i) {
		auto left = calcMaxMinResult(nums, ops, start, i, dp);
		auto right = calcMaxMinResult(nums, ops, i + 1, end, dp);

		if (ops[i] == '+') {
			maxResult = max(maxResult, left.first + right.first);
			minResult = min(minResult, left.second + right.second);
		}
		else if (ops[i] == '-') {
			maxResult = max(maxResult, left.first - right.second);
			minResult = min(minResult, left.second - right.first);
		}
	}

	dp[start][end] = { maxResult, minResult };
	return dp[start][end];
}

int solution(vector<string> arr)
{
	vector<int> nums;
	vector<char> ops;

	for (int i = 0; i < arr.size(); i++) {
		if (i % 2 == 0) {
			nums.push_back(stoi(arr[i]));
		}
		else {
			ops.push_back(arr[i][0]);
		}
	}

	int n = nums.size();
	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, { INT_MIN, INT_MAX }));

	return calcMaxMinResult(nums, ops, 0, n - 1, dp).first;
}