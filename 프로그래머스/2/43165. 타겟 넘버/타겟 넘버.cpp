#include <string>
#include <vector>

using namespace std;

// 재귀를 통해 
// target 값에 도달하는지 확인하기

int recur(int currentValue, const int targetValue, int index, const vector<int>& numbers)
{
	if (index == numbers.size())
	{
		if (currentValue == targetValue)
			return 1;

		return 0;
	}

	return recur(currentValue + numbers[index], targetValue, index + 1, numbers) + recur(currentValue - numbers[index], targetValue, index + 1, numbers);
}

int solution(vector<int> numbers, int target) {
	int answer = recur(0,target,0,numbers);

	return answer;
}