#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

vector<int> pv;

bool isPrior(int n)
{
	if (n <= 1)
		return false;

	if (n <= 3)
		return true;

	int ln = sqrt(n);

	for (int i = 2; i <= ln; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

void setting(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (isPrior(i))
			pv.push_back(i);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int left = 0, right = 0;
	int answer = 0;

	setting(n);

	int sum = 0;
	bool isNeedSum = true;
	int limit = pv.size();

	while (true)
	{
		if (isNeedSum)
		{
			if (right >= limit)
				break;

			sum += pv[right];
			right++;
		}
		else
		{
			if (left >= limit)
				break;

			sum -= pv[left];
			left++;
		}

		if (sum >= n)
		{
			if (sum == n)
				answer++;

			isNeedSum = false;
		}
		else
		{
			isNeedSum = true;
		}

	}

	cout << answer;
}