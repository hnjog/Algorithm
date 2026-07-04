#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[10];
		
		for (int i = 0; i < 10; i++)
		{
			cin >> arr[i];
		}

		double d = 0.0;
		int bm = arr[0], bb = arr[0];
		for (int i : arr)
		{
			d += i;
			if (bm > i)
				bm = i;
			if (bb < i)
				bb = i;
		}

		d -= bm;
		d -= bb;
		d /= 8.0;

		int ret = d + 0.5;

		cout << '#' << test_case << ' ' << ret << '\n';
	}
	return 0;
}