#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<vector<int>> maps(100, vector<int>(100, 0));

	for (int c = 0; c < 4; c++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				maps[i][j] = 1;
			}
		}
	}

	int count = 0;

	for (auto& v : maps)
	{
		for (int c : v)
		{
			count += c;
		}
	}

	cout << count;

	return 0;
}