#include<algorithm>

using namespace std;

int dfs(int s, int n)
{
	if (s == 0 || n == 0)
		return 0;

	int count = s / n;
	int lowValue = s - count * n;
	int highValue = (count + 1) * n - s;

	return min(dfs(lowValue, n / 10) + count, dfs(highValue, n / 10) + 1 + count);
}

int solution(int storey) {
	int startIdx = 1;
	while (startIdx < storey)
	{
		startIdx *= 10;
	}
	int answer = dfs(storey, startIdx);
	return answer;
}