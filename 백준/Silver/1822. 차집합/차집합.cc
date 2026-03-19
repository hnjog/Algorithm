#include<iostream>
#include<set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int an, bn;
	cin >> an >> bn;

	set<int> as;

	for (int i = 0; i < an; i++)
	{
		int t;
		cin >> t;
		as.insert(t);
	}

	for (int i = 0; i < bn; i++)
	{
		int t;
		cin >> t;
		if (as.find(t) != as.end())
			as.erase(t);
	}

	cout << as.size() << '\n';

	for (int i : as)
	{
		cout << i << ' ';
	}

	return 0;
}