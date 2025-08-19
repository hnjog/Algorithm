#include <string>
#include <vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
	int answer = 0;

	sort(score.begin(), score.end(),greater<int>());

	int boxCount = 0;
	int minBoxValue = INT_MAX;
	for (int a : score)
	{
		boxCount++;

		if (minBoxValue > a)
			minBoxValue = a;

		if (boxCount == m)
		{
			boxCount = 0;
			answer += m * minBoxValue;
			minBoxValue = INT_MAX;
		}
	}

	return answer;
}