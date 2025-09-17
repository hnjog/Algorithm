#include<iostream>
#include<math.h>

using namespace std;

const int primes[4] = { 2,3,5,7 };

int n;

bool isPrime(int x)
{
	if (x <= 1)
		return false;

	int sv = sqrt(x);

	for (int i = 2; i <= sv; i++)
	{
		if (x % i == 0)
			return false;
	}

	return true;
}


void recur(int now, int count)
{
	if (isPrime(now) == false)
		return;

	if (count == n)
	{
		cout << now << '\n';
		return;
	}

	if (count == n - 1)
	{
		for (int i = 1; i < 10; i += 2)
		{
			recur(now * 10 + i, count + 1);
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			recur(now * 10 + i, count + 1);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < 4; i++)
	{
		recur(primes[i], 1);
	}

	return 0;
}