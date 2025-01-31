#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

struct block
{
	int idx;
	int height;
};

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int maxV = 0;
	stack<block> st;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;

		if (st.empty())
		{
			st.push({ i,t });
			maxV = max(maxV, t);
		}
		else
		{
			int idx = i;
			while (st.empty() == false)
			{
				block b1 = st.top();
				// 새로 들어온 녀석이 
				// 최근에 들어온 녀석보다 작은 상황
				if (b1.height > t)
				{
					st.pop();
					int size = b1.height * (i - b1.idx);
					idx = b1.idx;
					maxV = max(maxV, size);
				}
				else
					break;
			}
			st.push({ idx,t });
		}
	}

	while (st.empty() == false)
	{
		block b1 = st.top();
		st.pop();
		int size = b1.height * (n - b1.idx);
		maxV = max(maxV, size);
	}

	cout << maxV;
}