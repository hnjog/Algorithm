#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int main()
{
	string l;
	getline(cin, l);

	bool bReverse = true;
	int nSize = l.size();

	string temp;

	for (int i = 0; i < nSize; i++)
	{
		char c = l[i];

		switch (c)
		{
		case '<':
		{
			reverse(temp.begin(), temp.end());
			cout << temp << '<';
			temp.clear();
			bReverse = false;
		}
			break;
		case '>':
		{
			cout << temp << '>';
			temp.clear();
			bReverse = true;
		}
			break;
		case ' ':
		{
			if (bReverse)
			{
				reverse(temp.begin(), temp.end());
			}
			
			cout << temp << ' ';
			temp.clear();
		}
			break;
		default:
			temp += c;
			break;
		}
	}

	if (temp.size() > 0)
	{
		reverse(temp.begin(), temp.end());
		cout << temp;
	}

	return 0;
}