#include<iostream>
#include<limits.h>

using namespace std;

typedef unsigned long long ull;

ull maxCount = LONG_MAX;

void recur(ull a, ull b, ull nowCount)
{
	if (a > b)
		return;

	if (nowCount > maxCount)
		return;

	if (a == b)
	{
		maxCount = nowCount;
		return;
	}

	recur(a * 10 + 1, b, nowCount + 1);
	recur(a * 2, b, nowCount + 1);
}

int main()
{
	ull a, b;
	cin >> a >> b;

	recur(a, b,0);

	if (maxCount != LONG_MAX)
		cout << maxCount + 1;
	else
		cout << -1;
}