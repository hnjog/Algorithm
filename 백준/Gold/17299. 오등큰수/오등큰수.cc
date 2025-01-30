#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(n,-1);
	stack<int> st1;
	stack<int> st2;
	unordered_map<int, int> count;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		count[t]++;
		st1.push(t);
	}

	int idx = n;

	while (st1.empty() == false)
	{
		int t = st1.top();
		st1.pop();
		idx--;

		if (st2.empty())
		{
			st2.push(t);
			continue;
		}
		else
		{
			int nowV = count[t];
			while (st2.empty() == false)
			{
				int t2 = st2.top();
				st2.pop();
				int prevV = count[t2];
				if (prevV > nowV)
				{
					st2.push(t2);
					vec[idx] = t2;
					break;
				}
			}
		}

		st2.push(t);
	}

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << ' ';
	}

}