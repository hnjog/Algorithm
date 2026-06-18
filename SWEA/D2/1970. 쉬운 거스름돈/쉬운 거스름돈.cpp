#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;

	const int coins[8] =
	{
		50000,
		10000,
		5000,
		1000,
		500,
		100,
		50,
		10
	};
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		int cs[8] = { 0, };

		for (int i = 0; i < 8; i++)
		{
			if (n >= coins[i])
			{
				cs[i] = n / coins[i];
				n -= (cs[i] * coins[i]);
			}
		}

		cout << '#' << test_case << '\n';
		for (int i = 0; i < 8; i++)
		{
			cout << cs[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}