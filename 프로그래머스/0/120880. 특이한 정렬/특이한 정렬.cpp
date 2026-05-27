#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
	vector<int> answer;

	int numListSize = numlist.size();
	answer.reserve(numListSize);

	for (int i = 0; i < numListSize; i++)
	{
		int answerSize = answer.size();
		int temp = abs(numlist[i] - n);

		bool isIn = false;
		for (int j = 0; j < answerSize; j++)
		{
			if (abs(answer[j] - n) >= temp)
			{
				isIn = true;
				if (abs(answer[j] - n) == temp &&
					answer[j] > numlist[i])
				{
					answer.insert(answer.begin() + j + 1, numlist[i]);
				}
				else
				{
					answer.insert(answer.begin() + j, numlist[i]);
				}
				break;
			}
		}

		if (isIn == false)
		{
			answer.push_back(numlist[i]);
		}
	}

	return answer;
}