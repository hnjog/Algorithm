#include<iostream>
#include<stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	stack<int> st;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int t2;
			cin >> t2;
			st.push(t2);
		}

		if (t == 2)
		{
			if (st.empty())
				cout << "-1" << '\n';
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}

		if (t == 3)
		{
			cout << st.size() << '\n';
		}

		if (t == 4)
		{
			if (st.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}

		if (t == 5)
		{
			if (st.empty())
				cout << "-1" << '\n';
			else
				cout << st.top() << '\n';
		}
	}

}
