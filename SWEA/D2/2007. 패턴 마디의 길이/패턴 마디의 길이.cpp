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

		string t1;

		for (int i = 1; i <= 10; i++)
		{
			t1.push_back(str[i - 1]);

			string t2 = str.substr(i, i);

			if (t1 == t2)
				break;
		}

		cout << '#' << test_case << ' ' << t1.size() << '\n';
	}
	return 0;
}