#include <string>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
	int answer = -1;

	const int limC = 8;
	unordered_set<int> values[limC];

	int sum = 0;

	for (int i = 0; i < limC; i++)
	{
		sum = N + sum * 10;
		values[i].insert(sum);
	}

	for (int i = 0; i < limC; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int a : values[j])
			{
				for (int b : values[i - j -1])
				{
					values[i].insert(a + b);
					values[i].insert(a - b);
					values[i].insert(a * b);

					if (b != 0)
						values[i].insert(a / b);
				}
			}
		}
	}

	for (int i = 0; i < limC; i++)
	{
		if (values[i].find(number) != values[i].end())
		{
			answer = i + 1;
			break;
		}
	}
	return answer;
}
