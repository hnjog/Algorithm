#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	// a^2 = b^2 + (t/2)^ 2
	double half = (double)t / 2;
	half *= half;
	int answer = round(half);

	cout << answer;
}