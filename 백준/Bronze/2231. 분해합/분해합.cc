#include<iostream>
#include<memory.h>

using namespace std;

int values[1001001] = { 0, };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(values, -1, sizeof(values));

	int ind = 1;
	int temp = 10;
	int sum = 0;

	for (int i = 0; i < 1000001; i++)
	{
		
		ind = 1;
		temp = 10;
		sum = i;

		while (true)
		{
			if (ind > i)
				break;

			temp = i % (ind * 10) / ind;
			ind *= 10;

			sum += temp;
		}

		if (values[sum] > i || values[sum] < 0)
			values[sum] = i;
	}

	for (int i = 0; i < 1001001; i++)
	{
		if (values[i] < 0)
			values[i] = 0;
	}

	int n = 0;


		cin >> n;
		cout << values[n] << '\n';

	return 0;
}
