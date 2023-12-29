#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	string number;
	cin >> number;

	bool bHax = false;
	bool bOct = false;

	if (number.size() > 1)
	{
		if (number[1] == 'x')
		{
			bHax = true;
		}
		else if (number[0] == '0')
		{
			bOct = true;
		}
	}

	vector<int> nums;
	size_t len = number.size();

	int sum = 0;
	int ind = 0;
	if (bHax)
	{
		const char as[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
		const int vals[6] = { 10,11,12,13,14,15 };
		for (size_t i = 2; i < len; i++)
		{
			char t = number[i];
			if (t >= '0' && t <= '9')
			{
				nums.push_back(t - '0');
			}
			else
			{
				for (size_t j = 0; j < 6; j++)
				{
					if (t == as[j])
					{
						nums.push_back(vals[j]);
						break;
					}
				}
			}
		}

		for(int i = nums.size() - 1; i >= 0; i--)
		{
			sum += nums[i] * pow(16 ,ind);
			ind++;
		}

		cout << sum;
	}
	else if (bOct)
	{
		for (size_t i = 1; i < len; i++)
		{
			char t = number[i];
			if (t >= '0' && t <= '9')
			{
				nums.push_back(t - '0');
			}
		}

		for (int i = nums.size() - 1; i >= 0; i--)
		{
			sum += nums[i] * pow(8 , ind);
			ind++;
		}

		cout << sum;
	}
	else
	{
		cout << atoi(number.c_str());
	}

	return 0;
}