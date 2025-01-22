#include<iostream>
#include<deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	deque<int> dq;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;

		switch (t)
		{
		case 1:
		{
			int t2;
			cin >> t2;
			dq.push_front(t2);
		}
		break;
		case 2:
		{
			int t2;
			cin >> t2;
			dq.push_back(t2);
		}
		break;
		case 3:
		{
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		break;
		case 4:
		{
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		break;
		case 5:
		{
			cout << dq.size() << '\n';
		}
		break;
		case 6:
		{
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		break;
		case 7:
		{
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}
		break;
		case 8:
		{
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}
		break;
		}
	}

}