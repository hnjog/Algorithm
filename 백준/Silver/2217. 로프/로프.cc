#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> rope(n);
	for (int i = 0; i < n; i++)
		cin >> rope[i];

	sort(rope.begin(), rope.end());

	int best = 0;
	for (int i = 0; i < n; i++)
	{
		int v = rope[i] * (n - i);
		if (v > best)
			best = v;
	}
	cout << best;

	return 0;
}