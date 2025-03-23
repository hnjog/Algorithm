#include<iostream>
#include<string>

using namespace std;

int main()
{
	int sum, n;
	cin >> sum >> n;

    int s = 0;
    for(int i = 0; i < n;i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        s += (t1 * t2);
    }
    
    if(sum == s)
        cout << "Yes";
    else
        cout << "No";

}