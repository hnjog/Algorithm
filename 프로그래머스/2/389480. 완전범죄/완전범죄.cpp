#include <algorithm>
#include <vector>

using namespace std;

// b가 현재것을 선택하는지 아닌지에 따라
// 재귀를 돌려보면 될것 같음
void dfs(const vector<vector<int>>& info, const int n, const int m, int nowA, int nowB, int nowIdx, int& answer)
{
	int iSize = info.size();

	if (nowA >= n || nowB >= m)
		return;

	if (answer != -1 &&
		nowA >= answer)
		return;

	if (nowIdx == iSize)
	{
		if (answer == -1)
			answer = nowA;
		else
			answer = min(nowA, answer);

		return;
	}
    
    dfs(info, n, m, nowA, nowB + info[nowIdx][1], nowIdx + 1, answer);
	dfs(info, n, m, nowA + info[nowIdx][0], nowB, nowIdx + 1, answer);
}

int solution(vector<vector<int>> info, int n, int m) {
	int answer = -1;
	sort(info.begin(), info.end(), [](const auto& a, const auto& b)
		{
			if (a[0] == b[0])
			    return a[1] < b[1];
            return a[0] > b[0];
		}
	);

	dfs(info, n, m, 0, 0, 0, answer);

	return answer;
}