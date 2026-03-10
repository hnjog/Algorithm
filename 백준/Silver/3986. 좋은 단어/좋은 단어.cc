#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		stack<char> st;
		string str;
		cin >> str;

		for (char c : str)
		{
			if (st.empty() == false &&
				st.top() == c)
			{
				st.pop();
			}
			else
			{
				st.push(c);
			}
		}

		if (st.empty())
			count++;
	}


	cout << count;

	return 0;
}