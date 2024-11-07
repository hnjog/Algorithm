#include <string>
#include <vector>

using namespace std;

long long nDp[21] = {0,};

long long getDepthCount(int depth)
{
	if (depth <= 1)
		return 1;

	if (nDp[depth] != 0)
		return nDp[depth];

	return nDp[depth] = getDepthCount(depth - 1) * depth;
}

bool Recur(const int lastN, const long long k, vector<int>& ret, vector<bool>& visit, int depth,long long nowCount)
{
	if (depth <= 0)
		return false;

	for (int i = 1; i <= lastN; i++)
	{
		if (visit[i])
			continue;
		
		long long value = getDepthCount(depth - 1);

		if (value + nowCount >= k)
		{
			visit[i] = true;
			ret.push_back(i);
			return Recur(lastN, k, ret, visit, depth - 1, nowCount);
		}
		else
		{
			nowCount += value;
		}
	}

	return false;
}

vector<int> startRecur(int n, long long k)
{
	vector<int> ret;
	vector<bool> visit(n + 1, false);

	Recur(n, k, ret, visit, n,0);

	return ret;
}

vector<int> solution(int n, long long k) {
	vector<int> answer = startRecur(n,k);

	return answer;
}