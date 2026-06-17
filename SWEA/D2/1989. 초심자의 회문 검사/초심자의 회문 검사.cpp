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

		bool bRot = true;

		int n = str.size();

		for (int i = 0; i <= n / 2; i++)
		{
			if (str[i] != str[n - i - 1])
			{
				bRot = false;
				break;
			}
		}

		cout << '#' << test_case << ' ' << bRot ? 1 : 0;
		cout << '\n';
	}
	return 0;
}