#include<iostream>
#include<string>

using namespace std;

void recur(int n)
{
	if (n == 0)
		return;

	cout << "long ";

	recur(n -= 4);
}

int main()
{
	int n;
	cin >> n;
	recur(n);
	cout << "int";
}