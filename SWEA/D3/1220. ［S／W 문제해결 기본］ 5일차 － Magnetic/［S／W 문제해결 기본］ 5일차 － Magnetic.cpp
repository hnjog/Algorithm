#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		vector<vector<char>> strs(n,vector<char>(n));
		vector<queue<char>> vq(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> strs[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (strs[j][i] != '0')
				{
					vq[i].push(strs[j][i]);
				}
			}
		}

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			while (vq[i].size() > 1)
			{
				char c = vq[i].front();
				vq[i].pop();

				if (c == '1' &&
					vq[i].front() == '2')
				{
					count++;
				}
			}
		}

		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;
}