#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	deque<pair<int,int>> dq;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		dq.push_back({ i + 1,t });
	}

	int com = dq.front().second;
	cout << dq.front().first << '\n';
	dq.pop_front();

	for (int i = 0; i < n - 1; i++)
	{
		int idx = com;

		if (idx < 0)
		{
			idx *= -1;
			idx--;
			while (idx > 0)
			{
				auto t2 = dq.back();
				dq.pop_back();
				dq.push_front(t2);
				idx--;
			}

			com = dq.back().second;
			cout << dq.back().first << '\n';
			dq.pop_back();
		}
		else
		{
			idx--;
			while (idx > 0)
			{
				auto t2 = dq.front();
				dq.pop_front();
				dq.push_back(t2);
				idx--;
			}

			com = dq.front().second;
			cout << dq.front().first << '\n';
			dq.pop_front();
		}
	}
}