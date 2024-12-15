#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
	if(scores.size() == 1)
        return 1;
    
    int answer = 1;
	vector<int> t = scores[0];

	vector<vector<int>> scoresA(scores.begin() + 1, scores.end());
	sort(scoresA.begin(), scoresA.end(), [](const vector<int>& a, const vector<int>& b)
		{
			if (a[0] == b[0])
				return a[1] > b[1];

			return a[0] > b[0];

		});

	int tSum = t[0] + t[1];
	int nowStep = scoresA[0][0];
	int nowMax = 0, prevMax = 0;

	for (int i = 0; i < scoresA.size(); i++)
	{
		vector<int>& now = scoresA[i];
		if (now[0] > t[0] && now[1] > t[1])
		{
			answer = -1;
			break;
		}

		if (nowStep != now[0])
		{
			prevMax = nowMax;
		}
		
		{
			// 여기에 들어온다면 이미 상위값에서 nowMax보다 큰 값이 존재한다는 뜻이다
			if (prevMax > now[1])
			{
				continue;
			}
			
			if (nowMax < now[1])
			{
				nowMax = now[1];
			}
		}
		
		int sum = now[0] + now[1];
		if (tSum < sum)
		{
			answer++;
		}

		nowStep = now[0];
	}

	return answer;
}