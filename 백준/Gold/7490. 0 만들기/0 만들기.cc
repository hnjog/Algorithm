#include<iostream>
#include<string>

using namespace std;

void recur(int n, int nowCount, string now, int sum, int lastv)
{
	if (nowCount > n)
	{
		if (sum + lastv == 0)
		{
			cout << now << '\n';
		}
		return;
	}

	char c = '0' + nowCount;

    
    int last = 0;
	if (lastv > 0)
		last = lastv * 10 + nowCount;
	else
		last = lastv * 10 - nowCount;

	string e = now + ' ' + c;
	recur(n, nowCount + 1, e, sum, last);
    
	e = now + '+' + c;
	recur(n, nowCount + 1, e, sum + lastv, nowCount);

	e = now + '-' + c;
	recur(n, nowCount + 1, e, sum + lastv, -nowCount);

	
}

int main()
{
	int t;
	cin >> t;

	while (t > 0)
	{
		int n;
		cin >> n;

		recur(n, 2, "1", 0, 1);
		cout << '\n';
		t--;
	}


	return 0;
}