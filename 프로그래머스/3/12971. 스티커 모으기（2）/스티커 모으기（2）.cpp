#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
	int sSize = sticker.size();

	if (sSize == 1)
		return sticker[0];

	int answer = 0;
	vector<int> dp(sSize, 0); // 0번째를 선택한 경우
	vector<int> dp2(sSize, 0); // 1번째를 선택한 경우

	dp[0] = sticker[0];
    dp[1] = sticker[0];
	dp2[1] = sticker[1];

	for (int i = 2; i < sSize; i++)
	{
		if (i == sSize - 1)
		{
			dp[i] = dp[i - 1];
			dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
		}
		else
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
			dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
		}
	}

	answer = max(dp[sSize - 1], dp2[sSize - 1]);

	return answer;
}