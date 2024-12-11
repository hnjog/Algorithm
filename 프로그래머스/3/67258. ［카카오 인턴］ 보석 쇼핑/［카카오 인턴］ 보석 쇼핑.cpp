#include <string>
#include <vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;

	unordered_set<string> gemSet(gems.begin(), gems.end());
	size_t arrayCount = gems.size();
	size_t gemCounts = gemSet.size();

	size_t startPointer = 0;
	size_t endPointer = gemCounts - 1;

	unordered_map<string, int> nowGem;

	for (int i = 0; i < gemCounts; i++)
	{
		nowGem[gems[i]]++;
	}

	int shortSize = -1;

	while (startPointer <= endPointer)
	{
		if (nowGem.size() == gemCounts)
		{
			if (shortSize == -1)
			{
				shortSize = endPointer - startPointer;
				answer.push_back(startPointer + 1);
				answer.push_back(endPointer + 1);
			}
			else if (shortSize > endPointer - startPointer)
			{
				shortSize = endPointer - startPointer;
				answer[0] = startPointer + 1;
				answer[1] = endPointer + 1;
			}

			nowGem[gems[startPointer]]--;
			if (nowGem[gems[startPointer]] == 0)
			{
				nowGem.erase(gems[startPointer]);
			}
			startPointer++;
		}
		else
		{
			endPointer++;
			if (endPointer >= arrayCount)
				break;
			nowGem[gems[endPointer]]++;
		}
	}

	return answer;
}