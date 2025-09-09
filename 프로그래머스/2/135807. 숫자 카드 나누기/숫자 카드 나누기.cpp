#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> getR(int m)
{
    if(m <= 1)
        return vector<int>();
    
    vector<int> ret;
    
    for(int i = m; i >= 2;i--)
    {
        if(m % i == 0)
        {
            ret.push_back(i);
            ret.push_back(m / i);
        }
    }
    
    sort(ret.begin(),ret.end(), greater<int>());
    
    return ret;
}

int findValue(vector<int>& tArr, vector<int>& nArr)
{
    int m = tArr[0];
    vector<int> vs = getR(m);
    for(int i : vs)
    {
        bool checkT = true, checkN = true;
        for(int t : tArr)
        {
            if(t % i != 0)
            {
                checkT = false;
                break;
            }
        }
        
        for(int n : nArr)
        {
            if(n % i == 0)
            {
                checkN = false;
                break;
            }
        }
        
        if(checkT && checkN)
        {
            return i;
        }
    }
    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());
    
    answer = findValue(arrayA,arrayB);
    answer = max(answer,findValue(arrayB,arrayA));
    return answer;
}