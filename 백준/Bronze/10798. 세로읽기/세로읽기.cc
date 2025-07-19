#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> vec;

	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}


	for (int s = 0; s < 15; s++)
	{
		for (string str : vec)
		{
			if (str.size() <= s)
				continue;

			cout << str[s];
		}
	}
}