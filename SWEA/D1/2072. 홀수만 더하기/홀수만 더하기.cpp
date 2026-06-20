#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int ret =0;
        for(int i=0;i<10;i++)
        {
            int t;
            cin >> t;
            if(t % 2 == 1)
                ret += t;
        }
        
        cout << '#' << test_case << ' ' << ret << '\n';
	}
	return 0;
}