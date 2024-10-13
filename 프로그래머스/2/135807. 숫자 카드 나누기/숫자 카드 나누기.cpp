#include <vector>
#include<algorithm>

using namespace std;

int check(vector<int>& a, vector<int>& b)
{
    int result = -1;
    
    int minV = a[0];
    
    for(int i = minV; i >= 2; i--)
    {
        bool fb = true;
        
        for(int t : a)
        {
            if(t % i != 0)
            {
                fb = false;
                break;
            }
        }
        
        if(fb == false)
            continue;
        
        bool sb = true;
        
        for(int t : b)
        {
            if(t % i == 0)
            {
                sb = false;
                break;
            }
        }
        
        if(sb == false)
            continue;
        
        result = i;
        break;
    }
    
    return result;
}

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    if(int aResult = check(a,b))
    {
        if(aResult > answer)
        {
            answer = aResult;
        }
    }
    
    if(int bResult = check(b,a))
    {
        if(bResult > answer)
        {
            answer = bResult;
        }
    }
    
    return answer;
}