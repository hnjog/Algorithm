#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
	unordered_set<int> us;
	for (int i = 0; i < 28; i++)
	{
		int t;
		cin >> t;
		us.insert(t);
	}

	for (int i = 1; i <= 30; i++)
	{
		if (us.find(i) == us.end())
			cout << i << '\n';
	}

	return 0;
}