#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	int idx = 0;
	bool swi = false;

	for (int i = 0; i < t * 2 - 1; i++)
	{
		bool stars = false;
		for (int j = 0; j < t * 2 - 1; j++)
		{
			int v = t - j - 1;
			if (v < 0)
				v *= -1;

			if (v <= idx)
			{
				stars = true;
				cout << '*';
			}
			else if(stars == false)
			{
				cout << ' ';
			}
			else
			{
				break;
			}
		}

		if (idx == t-1)
			swi = true;

		if (swi == false)
			idx++;
		else
			idx--;

		cout << '\n';
	}
}