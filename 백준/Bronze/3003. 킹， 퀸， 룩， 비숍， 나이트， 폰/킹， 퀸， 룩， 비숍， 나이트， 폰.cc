#include<iostream>
#include<vector>

using namespace std;

int main()
{
	const vector<int> c = { 1,1,2,2,2,8 };

	for (int i = 0; i < 6; i++)
	{
		int t;
		cin >> t;
		cout << c[i] - t << ' ';
	}
}