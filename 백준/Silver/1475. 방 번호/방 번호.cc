#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
	string n;
	cin >> n;

	unordered_map<char, int> vm;

	for (int i = 0; i <= 9; i++)
	{
		vm['0' + i] = 0;
	}

	int ns = n.size();

	for (int i = 0; i < ns; i++)
	{
		char c = n[i];
		int nv = vm[c];

		switch (c)
		{
		case '6':
		{
			if (nv > vm['9'])
			{
				vm['9']++;
			}
			else
			{
				vm[c]++;
			}
		}
			break;
		case '9':
		{
			if (nv > vm['6'])
			{
				vm['6']++;
			}
			else
			{
				vm[c]++;
			}
		}
			break;
		default:
		{
			vm[c]++;
		}
			break;
		}
	}

	int mv = 0;

	for (int i = 0; i <= 9; i++)
	{
		if (vm['0' + i] > mv)
		{
			mv = vm['0' + i];
		}
	}

	cout << mv;

	return 0;
}