#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long s;
	cin >> s;

	long long idx = 1;
	long long n = 0;
	long long count = 0;

	while (n < s)
	{
		n += idx;
		count++;
		idx++;
	}

	if (n > s)
		count--;

	cout << count;

	return 0;
}