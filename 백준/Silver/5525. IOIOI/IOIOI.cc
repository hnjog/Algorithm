#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;

	int result = 0;
	int count = 0;

	for (int i = 1; i < m - 1; i++)
	{
		if (str[i - 1] == 'I' &&
			str[i] == 'O' &&
			str[i + 1] == 'I')
		{
			count++;
			if (count >= n)
				result++;
			i++;
		}
		else
		{
			count = 0;
		}
	}

	cout << result;
	return 0;
}