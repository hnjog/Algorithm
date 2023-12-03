#include<iostream>
#include <vector>
#include<math.h>
using namespace std;

bool isPriority_Num(int _num)
{
	if (_num <= 1)
		return false;

	if (_num < 4)
		return true;

	size_t value = static_cast<size_t>(sqrt(_num) + 1);

	for (size_t i = 2; i <= value; i++)
	{
		if (_num % i == 0)
			return false;
	}

	return true;
}

int solution(vector<int> nums) {
	int answer = 0;

	// for을 3개 사용한다?
	size_t size = nums.size();

	if (size < 2)
	{
		return answer;
	}


	int sum;

	for (size_t i = 0; i < size - 2; i++)
	{
		for (size_t j = i + 1; j < size - 1; j++)
		{
			for (size_t k = j + 1; k < size; k++)
			{
				sum = nums[i] + nums[j] + nums[k];
				if (isPriority_Num(sum) == true)
				{
					answer++;
				}
			}
		}
	}

	return answer;
}