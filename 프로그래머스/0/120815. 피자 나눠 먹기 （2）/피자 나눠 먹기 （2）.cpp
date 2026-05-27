#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
	const int pizzaCount = 6;
	int num = n * pizzaCount;

	if (n % 6 == 0)
	{
		answer = n / 6;
	}
	else
	{
		for (int i = 6; i >= 2; i--)
		{
			if (pizzaCount % i == 0 &&
				n % i == 0)
			{
				num /= i;
			}
		}

		answer = (num - 1) / pizzaCount + 1;
	}
    
    return answer;
}