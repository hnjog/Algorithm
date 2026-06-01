#include<iostream>
#include<vector>

using namespace std;

int Recur(int k, const vector<int>& arr, int nowIdx, int nowVal)
{
	if (nowVal >= k)
	{
		if (nowVal == k)
			return 1;

		return 0;
	}

	int ret = 0;
	for (int i = nowIdx + 1; i < arr.size(); i++)
	{
		ret += Recur(k, arr, i, nowVal + arr[i]);
	}
	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			count += Recur(k, arr, i, arr[i]);
		}

		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;
}