#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> st;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;

		if (st.empty())
		{
			st.push(t);
			continue;
		}

		while(st.empty() == false &&
			t >= st.top())
		{
			st.pop();
		}

		st.push(t);
	}
	cout << st.size();
}