#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const string ppap = "PPAP";

int main()
{
	string str;
	cin >> str;

	string comp = "";
	
	for (char c : str)
	{
		comp.push_back(c);

		if (comp.size() < 4)
		{
			continue;
		}
		
		int idx = 0;

		bool isRight = true;

		for (int i = 3; i >= 0; i--)
		{
			if (comp[comp.size() - 1 - idx] != ppap[i])
			{
				isRight = false;
				break;
			}

			idx++;
		}

		if (isRight)
		{
			for (int i = 0; i < 4; i++)
				comp.pop_back();

			comp.push_back('P');
		}
	}

	if (comp == "P")
		cout << ppap;
	else
		cout << "NP";

	return 0;
}