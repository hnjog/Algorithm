#include<iostream>

using namespace std;

void func(int n, int now, int& answer)
{
	if (n <= 1)
		return;

	if (answer > 0 &&
		answer < n/ 2 + now)
		return;

	if (n % 5 == 0)
	{
		int v = n / 5 + now;
		if (v == answer)
			return;
		if (answer == -1)
			answer = v;
		else
			answer = min(answer, v);
	}

	if (n % 2 == 0)
	{
		int v = n / 2 + now;
		if (v == answer)
			return;

		if (answer == -1)
			answer = v;
		else
			answer = min(answer, v);
	}

	func(n - 5, now + 1, answer);
	func(n - 2, now + 1, answer);
}

int main()
{
	int n;
	cin >> n;
	int answer = -1;
	func(n, 0, answer);
	cout << answer;
}