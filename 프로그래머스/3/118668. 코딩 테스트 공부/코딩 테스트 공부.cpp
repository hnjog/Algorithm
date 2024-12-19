#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
	int answer = 0;
	const int MaxValue = INT_MAX / 2;
	const int limitV = 150;
	int targetAlp = -1, targetCop = -1;

	sort(problems.begin(), problems.end(), [](const vector<int>& a, const vector<int>& b)
		{
			return a[0] + a[1] < b[0] + b[1];
		});

	for (vector<int>& v : problems)
	{
		int alp_req = v[0];
		int cop_req = v[1];

		if (alp_req > targetAlp)
			targetAlp = alp_req;

		if (cop_req > targetCop)
			targetCop = cop_req;
	}

	vector<vector<int>> dp(limitV + 1, vector<int>(limitV + 1, MaxValue));

	dp[alp][cop] = 0;

	if (alp >= targetAlp)
	{
		for (int i = 0; i <= limitV; i++)
		{
			dp[i][cop] = 0;
		}
	}
	else
	{
		for (int i = alp + 1; i <= limitV; i++)
		{
			dp[i][cop] = dp[i - 1][cop] + 1;
		}
	}

	if (cop >= targetCop)
	{
		dp[alp] = vector<int>(limitV + 1, 0);
	}
	else
	{
		for (int i = cop + 1; i <= limitV; i++)
		{
			dp[alp][i] = min(dp[alp][i - 1] + 1, dp[alp][i]);
		}
	}

	for (int i = 0; i <= limitV; i++)
	{
		for (int j = 0; j <= limitV; j++)
		{
			if(i < limitV)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			if (j < limitV)
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

			for (vector<int>& v : problems)
			{
				int alp_req = v[0];

				if (i < alp_req)
					continue;
				int cop_req = v[1];
				if (j < cop_req)
					continue;

				int alp_rew = v[2];
				int cop_rew = v[3];
				int cost = v[4];

				int nextI = min(i + alp_rew, limitV);
				int nextJ = min(j + cop_rew, limitV);

				dp[nextI][nextJ] = min(dp[i][j] + cost, dp[nextI][nextJ]);

				if (nextI >= targetAlp && nextJ >= targetCop)
					dp[targetAlp][targetCop] = min(dp[targetAlp][targetCop], dp[nextI][nextJ]);
			}
		}
	}

	answer = dp[targetAlp][targetCop];

	return answer;
}
