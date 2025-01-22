#include<iostream>
#include<deque>
#include<vector>
#include<set>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	deque<int> q;
	set<int> idx;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			idx.insert(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (idx.find(i) != idx.end())
		{
			q.push_back(t);
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		q.push_front(t);
		cout << q.back() << ' ';
		q.pop_back();
	}
}