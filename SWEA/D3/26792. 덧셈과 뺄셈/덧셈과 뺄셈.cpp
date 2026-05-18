#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int ss, sm;
        cin >> ss >> sm;

        int a = (ss + sm) / 2;
        int b = ss - a;
        cout << a << " " << b << '\n';
	}
	return 0;
}