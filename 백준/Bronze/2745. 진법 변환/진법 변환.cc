#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<char, int> m1;

	char c = 'A';
	
	int v = 10;
	for (int i = 0; i < 26; i++)
	{
		char temp = c + i;
		int tempV = v + i;
		m1[temp] = tempV;
	}

	c = '0';
	for (int i = 0; i < 10; i++)
	{
		char temp = c + i;
		m1[temp] = i;
	}

	string s;
	cin >> s >> v;

	int result = 0;
	for (int i = 0;i<s.size();i++)
	{
		result *= v;

		char nc = s[i];

		result += m1[nc];
	}

	cout << result;

	return 0;
}