#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> stat(n);
	for (int i = 0; i < n; i++)
	{
		cin >> stat[i];
	}

	sort(stat.begin(), stat.end());

	// 가장 작은추가 1이 아니면 그냥 1이 정답이다
	if (stat[0] > 1)
	{
		cout << 1;
		return 0;
	}

	int value = stat[0];

	for (int i = 1; i < n; i++)
	{
		if (stat[i] > value + 1)
		{
			break;
		}

		value += stat[i];
	}

	cout << value + 1;

	return 0;
}