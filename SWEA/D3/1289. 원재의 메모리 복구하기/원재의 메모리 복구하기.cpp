#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		char now = '0';
		int count = 0;

		for (char c : str)
		{
			if (c != now)
			{
				count++;
				now = c;
			}
		}

		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;
}