#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a,b;
    for(int i =0;i<n;i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    
    for(int i =0;i<n;i++)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    sort(b.begin(),b.end(),greater<int>());
    
    int sum = 0;
    for(int i = 0; i <n;i++)
        sum += (a[i] * b[i]);
    
    cout<< sum;
}