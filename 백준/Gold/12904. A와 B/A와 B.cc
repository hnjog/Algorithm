#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool canA(string& a, string& b)
{
	if (a == b)
		return true;

	if (a.size() == b.size())
		return false;

	if (b.back() == 'A')
	{
		string t = b;
		t.pop_back();
		if (canA(a, t))
			return true;
	}

	if (b.back() == 'B')
	{
		string t = b;
		t.pop_back();
		reverse(t.begin(), t.end());
		if (canA(a, t))
			return true;

	}

	return false;
}

int main()
{
	string a, b;
	cin >> a >> b;

	cout << canA(a, b) ? 1 : 0;

	return 0;
}