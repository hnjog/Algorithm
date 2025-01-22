#include<iostream>
#include<stack>

using namespace std;

string suc = "Nice", Fai = "Sad";

int main()
{
	int n;
	cin >> n;

	int idx = 1;
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t != idx)
		{
			st.push(t);
		}
		else
		{
			idx++;
			if (st.empty())
				continue;

			while (st.empty() == false)
			{
				if (st.top() != idx)
					break;

				st.pop();
				idx++;
			}
		}
	}

	if (st.empty())
		cout << suc;
	else
		cout << Fai;
}