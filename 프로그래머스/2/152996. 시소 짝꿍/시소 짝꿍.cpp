#include <vector>
#include<algorithm>

using namespace std;

typedef long long ll;

ll solution(vector<int> weights) {
	ll answer = 0;

	sort(weights.begin(), weights.end());

	const int wSize = weights.size();

	for (int i = 0; i < wSize; i++)
	{
		int num = weights[i];

		int tn = num * 2;
		int ttn = num * 3;
		int fn = num * 4;

		for (int j = i + 1; j < wSize; j++)
		{
			int tNum = weights[j];

			// 배수를 맞출수 없는 상황
			if (tNum >= fn)
				break;

			if (tNum == num)
			{
				answer++;
				continue;
			}

			int doubleNum = tNum * 2;
			if (doubleNum > fn)
				break;

			int tripleNum = tNum * 3;
			int fourNum = tNum * 4;

			if (doubleNum == ttn ||
				doubleNum == fn ||
				tripleNum == fn)
				answer++;
		}
	}

	return answer;
}