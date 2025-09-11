#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		string c;
		cin >> c;

		if (c == "push")
		{
			int t;
			cin >> t;
			q.push(t);
		}
		else if (c == "pop")
		{
			if (q.empty() == false)
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else
			{
				cout << "-1" << '\n';
			}
		}
		else if (c == "size")
		{
			cout << q.size() << '\n';
		}
		else if (c == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (c == "front")
		{
			if (q.empty() == false)
			{
				cout << q.front() << '\n';
			}
			else
			{
				cout << "-1" << '\n';
			}
		}
		else if (c == "back")
		{
			if (q.empty() == false)
			{
				cout << q.back() << '\n';
			}
			else
			{
				cout << "-1" << '\n';
			}
		}
	}

	return 0;
}