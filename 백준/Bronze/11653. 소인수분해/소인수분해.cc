#include<iostream>
#include<math.h>

using namespace std;

int prime_Factor(int num)
{
	if (num <= 1)
	{
		return -1;
	}

	int result = num;

	for (int i = 2; i <= (int)sqrt(num); i++)
	{
		if (result % i == 0)
		{
			cout << i << '\n';
			result /= i;
			break;
		}
	}

	return result;
}

int main()
{
	int num = 0;
	cin >> num;

	int prevNum = 0;

	while (num > 1)
	{
		prevNum = num;
		num = prime_Factor(num);
		if (prevNum == num)
		{
			cout << num << '\n';
			break;
		}
	}

	return 0;
}