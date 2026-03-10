#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	unordered_map<string, int> sm;
	
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		sm[t]++;
	}

	string str;
	int mv = 0;
	for (const auto& p : sm)
	{
		if (p.second > mv)
		{
			mv = p.second;
			str = p.first;
		}
		else if (p.second == mv)
		{
			if (str > p.first)
			{
				str = p.first;
			}
		}
	}

	cout << str;

	return 0;
}