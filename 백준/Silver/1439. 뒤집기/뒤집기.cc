#include<iostream>
#include<string>

using namespace std;

int count(string& str, char start)
{
	int ret = 0;

	bool bContinued = false;

	for (char c : str)
	{
		if (c != start &&
			bContinued == false)
		{
			bContinued = true;
			ret++;
		}
		else if(c == start)
		{
			bContinued = false;
		}
	}

	return ret;
}

int main()
{
	string s;
	cin >> s;

	cout << min(count(s, '1'), count(s, '0'));

	return 0;
}