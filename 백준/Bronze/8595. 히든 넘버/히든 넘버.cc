#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
	size_t len;
	string number;
	cin >> len >> number;

	vector<ull> nums;

	const int dex = 10;
	ull tempNum = 0;

	for (size_t i = 0; i <= len; i++)
	{
		char t = number[i];
		if (t < '0' || t >'9')
		{
			if (tempNum > 0)
			{
				nums.push_back(tempNum);
				tempNum = 0;
			}
			continue;
		}

		int tt = t - '0';
		tempNum *= dex;
		tempNum += tt;
	}

	ull sum = 0;
	for (auto a : nums)
	{
		sum += a;
	}

	cout << sum;

	return 0;
}