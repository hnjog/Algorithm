#include <vector>

using namespace std;

typedef pair<int, int> pii;

void dfs(vector<vector<int>>& users, vector<pii>& sums, vector<int>& emoticons, int nowIdx, vector<int>& answer)
{
	int eCount = emoticons.size();

	if (nowIdx == eCount)
	{
		int plusC = 0, moneySum = 0;

		int usize = users.size();

		for (int i = 0; i < usize; i++)
		{
			int cut = users[i][1];
			int sum = sums[i].second;

			if (sum >= cut)
			{
				plusC++;
			}
			else
			{
				moneySum += sum;
			}
		}

		if (answer.empty())
		{
			answer.push_back(plusC);
			answer.push_back(moneySum);
			return;
		}

		if (answer[0] < plusC)
		{
			answer[0] = plusC;
			answer[1] = moneySum;
			return;
		}

		if (answer[0] == plusC &&
			answer[1] < moneySum)
		{
			answer[1] = moneySum;
		}
		return;
	}

	int nowv = emoticons[nowIdx];

	for (int dis = 10; dis <= 40; dis += 10)
	{
		int v = nowv * (100 - dis) / 100;

		for (pii& p : sums)
		{
			if (p.first <= dis)
			{
				p.second += v;
			}
		}

		dfs(users, sums, emoticons, nowIdx + 1, answer);

		for (pii& p : sums)
		{
			if (p.first <= dis)
			{
				p.second -= v;
			}
		}
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;

	int usize = users.size();

	vector<pii> sums;
	sums.reserve(usize);

	for (auto& u : users)
	{
		sums.push_back({ u[0],0 });
	}

	dfs(users, sums, emoticons, 0, answer);

	return answer;
}