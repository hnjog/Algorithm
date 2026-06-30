#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        cin >> n;
        
        int ret = 0;
        for(int i=1;i<=n;i++)
        {
            if(i%2 == 0)
                ret -= i;
            else
                ret +=i;

        }

        cout << '#' << test_case << ' ' << ret << '\n';
	}
	return 0;
}