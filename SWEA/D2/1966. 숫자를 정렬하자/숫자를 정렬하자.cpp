#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());

		cout << '#' << test_case << ' ';
		for (int i : arr)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}