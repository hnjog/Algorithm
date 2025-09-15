#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

const int divV = 1000000007;

int find(vector<int>& fs, int x)
{
	if (fs[x] == x)
		return x;

	return fs[x] = find(fs, fs[x]);
}

void UnionF(vector<int>& fs, int a, int b)
{
	int ap = find(fs, a);
	int bp = find(fs, b);

	if (ap != bp)
		fs[ap] = bp;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> fset(n + 1);
	for (int i = 0; i <= n; i++)
		fset[i] = i;

	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		UnionF(fset, t1, t2);
	}

	unordered_map<int, int> um;

	for (int i = 1; i <= n; i++)
		um[find(fset,i)]++;

	long long answer = 1;

	for (auto& p : um)
	{
		answer *= p.second;
		answer %= divV;
	}

	cout << answer;

	return 0;
}