#include<iostream>
#include<string>

using namespace std;

int recur(const string& str,int start, int end, bool useCount)
{
	if (start >= end)
	{
		if (useCount)
			return 1;
		
		return 0;
	}

	if (str[start] == str[end])
	{
		return recur(str, start + 1, end - 1, useCount);
	}

	if (useCount == false)
	{
		int v = recur(str, start + 1, end, true);
		if (v == 2)
			v = recur(str, start, end - 1, true);

		return v;
	}

	return 2;
}


int main()
{
	int t;
	cin >> t;

	string str;
	for (; t > 0; t--)
	{
		cin >> str;
		cout << recur(str, 0, str.size() - 1, false) << '\n';
	}

	return 0;
}