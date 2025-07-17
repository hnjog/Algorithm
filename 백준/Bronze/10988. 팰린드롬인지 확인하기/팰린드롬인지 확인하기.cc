#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int sSize = s.size();
	for (int i = 0; i < sSize / 2; i++)
	{
		char c1 = s[i];
		char c2 = s[sSize - i - 1];
		if (c1 != c2)
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}