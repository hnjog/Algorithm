#include<iostream>
#include<vector>
#include<unordered_set>

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
		vector<int> vals(n);
		for (int i = 0; i < n; i++)
			cin >> vals[i];

		vector<bool> visit(10001,false);
		visit[0] = true;

		for (int v : vals)
		{
			for (int i = 10000; i >= v; i--)
			{
				if (visit[i - v])
					visit[i] = true;
			}
		}

		int count = 0;
		for (int i = 0; i <= 10000; i++)
			if (visit[i])
				count++;

		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;
}