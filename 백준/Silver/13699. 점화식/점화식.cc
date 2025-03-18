#include<iostream>
#include<vector>

using namespace std;

uint64_t arr[36] = {0,};

uint64_t func(int n)
{
	if (n < 0)
		return 0;

	if (arr[n] != 0)
		return arr[n];

	uint64_t sum = 0;
	for (int i = 0; i < n / 2; i++)
	{
		sum += (func(i) * func(n - 1 - i));
	}
	arr[n] = sum * 2;
	if (n % 2 == 1)
	{
		arr[n] += (func(n / 2) * func(n / 2));
	}

	return arr[n];
}

int main()
{
	int n;
	cin >> n;
	arr[0] = 1;
	
	cout << func(n);
}