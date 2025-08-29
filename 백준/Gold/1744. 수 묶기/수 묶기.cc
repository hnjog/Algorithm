#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum = 0;

	priority_queue<int, vector<int>> pH;
	priority_queue<int, vector<int>,greater<int>> mH;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;

		if (t == 1)
		{
			sum += t;
		}
		else if (t > 1)
		{
			pH.push(t);
		}
		else
		{
			mH.push(t);
		}
	}

	while (pH.empty() == false)
	{
		int p = pH.top();
		pH.pop();

		if (pH.empty() == false)
		{
			sum += (p * pH.top());
			pH.pop();
		}
		else
		{
			sum += p;
		}
	}

	while (mH.empty() == false)
	{
		int m = mH.top();
		mH.pop();

		if (mH.empty() == false)
		{
			sum += (m * mH.top());
			mH.pop();
		}
		else
		{
			sum += m;
		}
	}

	cout << sum;

	return 0;
}