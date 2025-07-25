#include<iostream>
#include<map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, int> m;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		m[t]++;
	}

	int t;
	cin >> t;
	cout << m[t];

	return 0;
}