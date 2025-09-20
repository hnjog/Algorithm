#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> heis(n);
	for (int i = 0; i < n; i++)
		cin >> heis[i];

	vector<int> st;
	st.push_back(heis[0]);

	long answer = 0;
	for (int i = 1; i < n; i++)
	{
		int h = heis[i];
		while (st.empty() == false &&
			h >= st.back())
		{
			st.pop_back();
			answer += st.size();
		}

		st.push_back(h);
	}

	while (st.empty() == false)
	{
		st.pop_back();
		answer += st.size();
	}

	cout << answer;

	return 0;
}