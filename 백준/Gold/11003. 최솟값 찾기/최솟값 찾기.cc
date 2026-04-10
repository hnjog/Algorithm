#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, l;
	cin >> n >> l;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	deque<pair<int, int>> dq;

	vector<int> ret;
	ret.reserve(n);


	for (int i = 0; i < n; i++)
	{
		while (dq.empty() == false &&
			dq.back().second > arr[i])
		{
			dq.pop_back();
		}

		while (dq.empty() == false && 
			dq.front().first < i - l + 1)
		{
			dq.pop_front();
		}

		dq.push_back({ i,arr[i] });
		ret.push_back(dq.front().second);
	}

	for (int i : ret)
	{
		cout << i << ' ';
	}

	return 0;
}