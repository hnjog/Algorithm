#include<iostream>
#include<unordered_map>

using namespace std;

typedef unsigned long long ull;

ull GetValue(unordered_map<ull, ull>& um, ull p, ull q, ull n)
{
	if (um.find(n) != um.end())
	{
		return um[n];
	}

	return um[n] = GetValue(um, p, q, n / p) + GetValue(um, p, q, n / q);
}

int main()
{
	ull n, p, q;
	cin >> n >> p >> q;

	unordered_map<ull, ull> um;

	um[0] = 1;

	cout << GetValue(um,p,q,n);

	return 0;
}