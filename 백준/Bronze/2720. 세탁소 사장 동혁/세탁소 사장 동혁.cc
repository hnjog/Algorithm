#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	const int coinValue[4] = { 25,10,5,1 };

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int v;
		cin >> v;

		for (int j = 0; j < 4; j++)
		{
			cout << v / coinValue[j];
			if (j != 3)
				cout << ' ';
			v %= coinValue[j];
		}

		cout << '\n';
	}

}