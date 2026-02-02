#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	string t;
	cin >> t;

	size_t n = t.size();

	map<char, int> cm;
	
	for (size_t i = 0; i < n; i++)
	{
		cm[t[i]]++;
	}

	bool onlySingleOnce = false;
	char onlyone;

	for (auto& p : cm)
	{
		if (p.second % 2 == 1)
		{
			if (onlySingleOnce)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else
			{
				onlySingleOnce = true;
				onlyone = p.first;
				p.second--;
			}
		}

		p.second /= 2;
	}

	int ta = n / 2;

	string test;

	auto p = cm.begin();

	for (int i = 0; i < ta; i++)
	{
		while (p->second == 0)
		{
			p++;
		}

		test.push_back(p->first);
		p->second--;
	}

	string rt = test;
	reverse(rt.begin(), rt.end());

	if (onlySingleOnce)
	{
		cout << test << onlyone << rt;
	}
	else
	{
		cout << test << rt;
	}
	return 0;
}