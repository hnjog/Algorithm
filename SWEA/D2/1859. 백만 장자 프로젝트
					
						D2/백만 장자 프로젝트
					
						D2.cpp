#include<iostream>
#include<stack>

using namespace std;

typedef pair<long, long> pii;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		long val = 0;
		stack<pii> st;

		for (int i = 0; i < n; i++)
		{
			long t;
			cin >> t;
			if (st.empty() ||
				st.top().first > t)
			{
				st.push({t,1});
				continue;
			}
			
			if (st.top().first == t)
			{
				st.top().second++;
				continue;
			}

			pii p = { t,1 };

			while (st.empty() == false &&
				st.top().first < t)
			{
				val += (t - st.top().first) * st.top().second;
				p.second += st.top().second;
				st.pop();
			}

			st.push(p);
		}

		cout << '#' << test_case << ' ' << val << '\n';
	}
	return 0;
}