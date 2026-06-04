#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 1;

	unordered_set<char> us = { '3','6','9' };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			string t = to_string(i);

			int count = 0;
			for (char c : t)
			{
				if (us.find(c) != us.end())
				{
					count++;
				}
			}

			if (count == 0)
			{
				cout << i;
			}
			else
			{
				for (int i = 0; i < count; i++)
					cout << '-';
			}
			
			cout << ' ';
		}

		cout << '\n';
	}
	return 0;
}