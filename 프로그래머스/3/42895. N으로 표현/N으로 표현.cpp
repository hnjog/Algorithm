#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
	int answer = -1;

	const int lastCount = 8;
	unordered_set<int> valueSet[lastCount];

	int sum = 0;
	for (int i = 0; i < lastCount; i++)
	{
		sum = N + sum * 10;
		valueSet[i].insert(sum);
	}

	for (int i = 1; i < lastCount; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (const auto& jValue : valueSet[j])
			{
				for (const auto& value : valueSet[i - j - 1])
				{
					valueSet[i].insert(jValue + value);
					valueSet[i].insert(jValue - value);
					valueSet[i].insert(jValue * value);

					if(value != 0)
						valueSet[i].insert(jValue / value);
				}
			}
		}
	}

	for (int i = 0; i < lastCount; i++)
	{
		if (valueSet[i].find(number) != valueSet[i].end())
		{
			answer = i + 1;
			break;
		}
	}

	return answer;
}