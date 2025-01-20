#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isRightDis(vector<int>& vec, int dis, int c)
{
	c--;
	int nowDis = vec[0] + dis;

	for (int i = 1; i < vec.size(); i++)
	{
		if (nowDis <= vec[i])
		{
			c--;
			nowDis = vec[i] + dis;
		}
	}

	if (c > 0)
		return false;

	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;

	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vec.push_back(t);
	}

	sort(vec.begin(), vec.end());

	int low = 1, high = vec[n-1] - vec[0] + 1;
	int mid = 0;

	while (low < high)
	{
		mid = (low + high) / 2;
		if (mid == low)
			break;

		if (isRightDis(vec, mid, c))
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}

	cout << low;

	return 0;
}