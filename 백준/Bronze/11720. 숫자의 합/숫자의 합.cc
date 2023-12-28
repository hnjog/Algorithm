#include<iostream>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    int sum = 0;
    char a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        sum += (a - 48);
    }

    cout << sum;
	return 0;
}