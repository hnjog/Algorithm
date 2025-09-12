#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> vec;
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		vec.push_back(t);
	}

	sort(vec.begin(), vec.end(), []
	(const string& a, const string& b)
		{
			if (a.size() == b.size())
			{
				int aSum = 0, bSum = 0;
				for (char c : a)
				{
					if (isdigit(c))
						aSum += (c - '0');
				}

				for (char c : b)
				{
					if (isdigit(c))
						bSum += (c - '0');
				}

				if (aSum == bSum)
				{
					return a < b;
				}

				return aSum < bSum;
			}

			return a.size() < b.size();
		});

	for (auto& s : vec)
	{
		cout << s << '\n';
	}

	return 0;
}