#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(n, 0);

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vec[i] = t;
	}

	sort(vec.begin(), vec.end());

	int x;
	cin >> x;

	int left = 0, right = n - 1;
	int answer = 0;

	while (left < right)
	{
		int lV = vec[left];
		int rV = vec[right];

		if (lV >= x)
			break;

		if (rV >= x ||
			lV + rV > x)
		{
			right--;
			continue;
		}

		if (lV + rV == x)
		{
			answer++;
			left++;
			right--;
			continue;
		}

		left++;
	}

	cout << answer;
}