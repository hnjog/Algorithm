#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	string str;
	cin >> str;

	string findStr = "I";
	for (int i = 0; i < n; i++)
		findStr += "OI";

	int result = 0;

	int fSize = findStr.size();

	for (int i = 0; i < str.size() - fSize + 1; i++)
	{
		if (str[i] == 'I')
		{
			string temp(str.begin() + i, str.begin() + i + fSize);
			if (temp == findStr)
				result++;
		}
	}

	cout << result;
	return 0;
}