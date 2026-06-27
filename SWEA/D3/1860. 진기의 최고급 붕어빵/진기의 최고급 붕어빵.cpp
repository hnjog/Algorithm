#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> guests(n);

		for (int i = 0; i < n; i++)
			cin >> guests[i];

		sort(guests.begin(), guests.end());

		bool resultCheck = true;

		for (int i = 0; i < n; i++)
		{
			int nowCount = (guests[i] / m) * k - i - 1;
			if (nowCount < 0)
			{
				resultCheck = false;
				break;
			}
		}

		string str;

		if (resultCheck)
		{
			str = "Possible";
		}
		else
		{
			str = "Impossible";
		}

		cout << '#' << test_case << ' ' << str << '\n';
	}
	return 0;
}