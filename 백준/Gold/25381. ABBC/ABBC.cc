#include<iostream>
#include<queue>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string str;
	cin >> str;


	int answer = 0;
	deque<char> dq;
	// bc 검사
	for (char c : str)
	{
		if (dq.empty() == false
			&& c == 'C')
		{
			stack<char> st;
			while (dq.empty() == false &&
				dq.front() != 'B')
			{
				st.push(dq.front());
				dq.pop_front();
			}

			if (dq.empty() == false &&
				dq.front() == 'B')
			{
				answer++;
				dq.pop_front();
			}

			while (st.empty() == false)
			{
				dq.push_front(st.top());
				st.pop();
			}
		}
		else
			dq.push_back(c);
	}

	int dSize = dq.size();
	for (int i = 0; i < dSize; i++)
	{
		if (dq.size() <= 1)
			break;

		if (dq.front() == 'A')
		{
			stack<char> st;
			st.push(dq.front());
			dq.pop_front();

			while (dq.empty() == false &&
				dq.front() != 'B')
			{
				st.push(dq.front());
				dq.pop_front();
			}

			if (dq.empty() == false &&
				dq.front() == 'B')
			{
				answer++;
				dq.pop_front();
				st.pop();
			}
			while (st.empty() == false)
			{
				dq.push_front(st.top());
				st.pop();
			}
		}
		else
			dq.pop_front();
	}

	cout << answer;
}