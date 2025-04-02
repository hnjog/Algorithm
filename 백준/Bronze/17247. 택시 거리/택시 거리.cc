#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int x1, x2, y1, y2;
	bool isOne = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t;
			cin >> t;
			if (t == 1)
			{
				if (isOne == false)
				{
					y1 = i;
					x1 = j;
					isOne = true;
				}
				else
				{
					y2 = i;
					x2 = j;
				}
			}

		}
	}

	cout << abs(x2 - x1) + abs(y2 - y1);
}