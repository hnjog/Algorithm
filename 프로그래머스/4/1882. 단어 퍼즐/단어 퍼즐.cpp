#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<string> strs, string t) {
	unordered_set<string> dict(strs.begin(), strs.end());

	const int tSize = t.size();

	// dp[i]는 t의 첫 i글자를 만드는데 필요한 최소 횟수
	vector<int> dp(tSize + 1, tSize + 1);

	dp[0] = 0; // 빈 문자열을 만드는 데 필요한 횟수는 0

	for (int i = 1; i <= tSize; ++i)
	{
		// strs의 모든 문자열 길이는 최대 5이므로
		for (int j = 1; j <= 5; ++j)
		{
			// i-j부터 추출하기
			// 현재의 i 부터
			// j로 좌측으로 당기면서 부분 문자열을 추출하고
			// 그것을 비교하는 방식이다
			if (i - j >= 0)
			{
				// i~j의 위치부터, j의 길이까지 추출하기
				// t의 부분들을 '잘라'
				// 해당 단어 부분이 'strs' 로 만든 set에 있는지 확인한다
				string part = t.substr(i - j, j);
				if (dict.find(part) != dict.end())
				{
					// 단어가 있다면 dp[i]에 기존 것과
					// dp[i-j] + 1과 비교
					dp[i] = min(dp[i], dp[i - j] + 1);
				}
			}
		}
	}

	int answer = -1;
	if (dp[tSize] != tSize + 1)
		answer = dp[tSize];

	return answer;
}