#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	char c;
	cin >> c;

	int p;

	switch (c)
	{
	case 'Y':
	{
		p = 1;
	}
		break;
	case 'F':
	{
		p = 2;
	}
	break;
	case 'O':
	{
		p = 3;
	}
	break;
	}

	unordered_set<string> ss;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		ss.insert(str);
	}

	cout << ss.size() / p;

	return 0;
}