#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	map<int, char> m1;

	char c = 'A';

	int v = 10;
	for (int i = 0; i < 26; i++)
	{
		char temp = c + i;
		int tempV = v + i;
		m1[tempV] = temp;
	}

	c = '0';
	for (int i = 0; i < 10; i++)
	{
		char temp = c + i;
		m1[i] = temp;
	}

	int s;
	cin >> s >> v;

	string result = "";
	
	while (true)
	{
		int t = s % v;
		s /= v;

		result += m1[t];
		
		if (s < v)
			break;
	}

	if(s != 0)
	    result += m1[s];

	reverse(result.begin(), result.end());

	cout << result;

	return 0;
}