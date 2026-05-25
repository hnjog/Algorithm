#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int n;
		cin >> n;
		vector<int> heights(n);
		for (int i = 0; i < n; i++)
			cin >> heights[i];

		int val = 0;
		for (int i = 2; i < n - 2; i++)
		{
			int lv = min(heights[i] - heights[i - 2], heights[i] - heights[i - 1]);
			int rv = min(heights[i] - heights[i + 2], heights[i] - heights[i + 1]);

			if (lv <= 0 || rv <= 0)
				continue;

			val += min(lv, rv);
		}

		cout << '#' << test_case << ' ' << val << '\n';
	}

	return 0;
}