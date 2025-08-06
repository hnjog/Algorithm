#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ip;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		ip.push_back(t);
	}

	int answer = 0;
	vector<int> sums(n + 1, 0);
	sums[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		sums[i] = sums[i - 1] + ip[i-1];
	}

	int i = 1, j = 0;

	while (true)
	{
		int nowSum = sums[i] - sums[j];

		bool bOveri = false;

		if (i >= n)
			bOveri = true;


		if (nowSum == m)
		{
			answer++;

			if (bOveri == false)
				i++;
			else
				j++;
		}
		else if (nowSum > m)
		{
			j++;
		}
		else
		{
			if (bOveri == false)
				i++;
			else
				j++;
		}

		if (i >= n && j >= n)
			break;
	}

	cout << answer;
}