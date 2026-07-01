#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		int pro[5] = { 2,3,5,7,11 };
		int pri[5] = { 0, };

		for (int i = 0; i < 5; i++)
		{
			while (n % pro[i] == 0)
			{
				pri[i]++;
				n /= pro[i];
			}
		}


		cout << '#' << test_case << ' ';

		for (int i = 0; i < 5; i++)
			cout << pri[i] << ' ';

		cout << '\n';
	}
	return 0;
}