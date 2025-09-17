#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

const string r = "Goldbach's conjecture is wrong.";

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	unordered_set<int> odPrimesSet;
	odPrimesSet.reserve(1000000 / 2);

	for (int i = 3; i < 1000000; i += 2)
	{
		if (isPrime(i))
		{
			odPrimesSet.insert(i);
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;

		bool bFind = false;
		int v1, v2;

		for (int i = 3; i <= n / 2; i += 2)
		{
			if (odPrimesSet.find(i) != odPrimesSet.end() &&
				odPrimesSet.find(n - i) != odPrimesSet.end())
			{
				v1 = i;
				v2 = n - i;
				bFind = true;
				break;
			}
		}

		if (bFind == false)
			cout << r << '\n';
		else
			cout << n << " = " << v1 << " + " << v2 << '\n';
	}

}