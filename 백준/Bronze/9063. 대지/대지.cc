#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int miny = 10004, minx = 10004;
	int maxy = -10004, maxx = -10004;
	
	for (int i = 0; i < n; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;

		if (t1 < minx)
			minx = t1;
		if (t1 > maxx)
			maxx = t1;

		if (t2 < miny)
			miny = t2;
		if (t2 > maxy)
			maxy = t2;
	}

	cout << (maxx - minx) * (maxy - miny);

}