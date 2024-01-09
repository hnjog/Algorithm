#include<iostream>
#include<vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> cards;
	cards.reserve(n);

	int temp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		cards.push_back(temp);
	}

	int maxResult = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				temp = cards[i] + cards[j] + cards[k];
				if (temp > m)
				{
					continue;
				}

				if (temp > maxResult)
				{
					maxResult = temp;
				}
			}
		}
	}

	cout << maxResult;

	return 0;
}