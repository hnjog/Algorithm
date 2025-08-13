#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	stack<char> st;
	string str;
	cin >> str;

	size_t idx = 0;
	size_t ssize = str.size();

	int answer = 0;

	while (idx < ssize)
	{
		if (str[idx] == '(')
		{
			if (str[idx + 1] == ')')
			{
				answer += st.size();
				idx++;
			}
			else
			{
				st.push('(');
			}
		}
		else
		{
			if (st.empty() == false)
			{
				answer++;
				st.pop();
			}
		}
		idx++;
	}

	cout << answer;

	return 0;
}