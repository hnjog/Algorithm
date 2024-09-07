#include <vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int solution(vector<int> arr) {
	int answer = 0;
	sort(arr.begin(), arr.end());
	int aSize = arr.size();
	int maxV = arr[aSize - 1];

	for (int i = maxV; i <= INT_MAX; i++)
	{
		bool isFind = true;
		for (int j = 0; j < aSize; j++)
		{
			if (i % arr[j] != 0)
			{
				isFind = false;
				break;
			}
		}

		if (isFind)
		{
			answer = i;
			break;
		}
	}

	return answer;
}