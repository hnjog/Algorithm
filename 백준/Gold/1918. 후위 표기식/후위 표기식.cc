#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> st;
	string ret = "";

	// 
	// 연산자 출력 조건
	// 
	// 1. () 가 가장 높기에
	// ) 를 만나면 지금까지 가지고 있는 연산자 모두 push함
	// 
	// 2. * / /는 뒤에 오는 연산자가 ()가 아니라면
	//    지금까지의 연산자 모두 push
	// 
	// 3. +/- 다음에 만난 연산자가 +/- 라면
	//    지금까지 만난 연산자 모두 push
	// 
	//

	for (char c : s)
	{
		if (c >= 'A' && c <= 'Z')
			ret.push_back(c);

		if (c == '(')
		{
			st.push(c);
		}

		if (c == '+' ||
			c == '-')
		{
			if(st.empty() == false)
			{
				while (st.empty() == false)
				{
					char temp = st.top();
					if (temp == '+' ||
						temp == '-' ||
						temp == '*' ||
						temp == '/')
					{
						ret.push_back(temp);
						st.pop();
					}
					else
					{
						break;
					}
				}
			}
			st.push(c);
		}

		if (c == '*' ||
			c == '/')
		{
			if (st.empty() == false)
			{
				while (st.empty() == false)
				{
					char temp = st.top();
					if (temp == '*' ||
						temp == '/')
					{
						ret.push_back(temp);
						st.pop();
					}
					else
					{
						break;
					}
				}
			}
			st.push(c);
		}
		
		if (c == ')')
		{
			while (st.empty() == false)
			{
				char temp = st.top();
				st.pop();
				if (temp == '(') 
				{
					break;
				}
				else
				{
					ret.push_back(temp);
				}
			}
		}
	}

	while (st.empty() == false)
	{
		ret.push_back(st.top());
		st.pop();
	}

	cout << ret;

	return 0;
}