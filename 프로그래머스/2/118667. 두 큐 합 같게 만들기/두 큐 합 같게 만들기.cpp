#include <string>
#include <vector>
#include<queue>

using namespace std;

bool dfs(deque<int>& q1, deque<int>& q2, int maxCount, int nowCount, long targetSum, long q1Sum, int& answer)
{
	if (targetSum == q1Sum)
	{
		if (answer < 0)
		{
			answer = nowCount;
		}
		else if (answer > nowCount)
		{
			answer = nowCount;
		}
		return true;
	}

	if (nowCount >= maxCount ||
		(answer > 0 && nowCount >= answer))
		return false;

	if (q1.empty() || q2.empty())
		return false;

	if(q1Sum > targetSum)
	{
		// q1껄 빼서 q2에 넣음
		int t = q1.front();
		q1.pop_front();
		q1Sum -= t;

		q2.push_back(t);
	}
	else
	{
		// q2껄 빼서 q1에 넣음
		int t = q2.front();
		q2.pop_front();

		q1.push_back(t);
		q1Sum += t;
	}
	return dfs(q1, q2, maxCount, nowCount + 1, targetSum, q1Sum, answer);
}

int solution(vector<int> queue1, vector<int> queue2) {
	int answer = -1;
	long sum = 0;
	long targetSum = 0;

	deque<int> q1, q2;
	long q1Sum = 0;
	long q2Sum = 0;

	for (int q1s : queue1)
	{
		q1.push_back(q1s);
		q1Sum += q1s;
	}

	sum += q1Sum;

	for (int q2s : queue2)
	{
		q2.push_back(q2s);
		q2Sum += q2s;
	}

	sum += q2Sum;

	// 합 자체가 짝수가 아니면 두 큐의 합을 같게 만들 수 없음
	if (sum % 2 != 0)
		return -1;

	if (q1Sum == q2Sum)
		return 0;

	targetSum = sum / 2;

	int maxCount = queue1.size() * 3 + 1;

	dfs(q1, q2, maxCount, 0, targetSum, q1Sum, answer);

	return answer;
}