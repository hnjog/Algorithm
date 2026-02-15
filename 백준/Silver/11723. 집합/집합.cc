#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	unordered_set<int> uSet;
	uSet.reserve(20);
	vector<int> av;

	for (int t = 1; t <= 20; t++)
		av.push_back(t);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "add")
		{
			int t;
			cin >> t;
			uSet.insert(t);
		}

		if (s == "remove")
		{
			int t;
			cin >> t;
			uSet.erase(t);
		}

		if (s == "check")
		{
			int t;
			cin >> t;

			bool bf = uSet.find(t) != uSet.end();
			if (bf)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}

		if (s == "toggle")
		{
			int t;
			cin >> t;

			bool bf = uSet.find(t) != uSet.end();
			if (bf)
			{
				uSet.erase(t);
			}
			else
			{
				uSet.insert(t);
			}
		}

		if (s == "all")
		{
			uSet.insert(av.begin(), av.end());
		}

		if (s == "empty")
		{
			uSet.clear();
		}
	}

	return 0;
}