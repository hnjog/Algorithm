#include <map>
#include <vector>
#include <iostream>

using namespace std;

int getN(int k, map<int,double>& poss)
{
    int idx = 0;
    int prevValue = 0;
    
    while(k > 1)
    {
        prevValue = k;
        
        if(k % 2 == 0)
            k /=2;
        else
        {
            k *= 3;
            k++;
        }
        
        if(prevValue != 0)
        {
            double value = min(k,prevValue);
            double tempk = k - value;
            double tempp = prevValue - value;
            value += max(tempk , tempp) / 2;
            poss[idx] = value;
        }
        
        idx++;
    }
    
    return idx;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    map<int,double> poss;
    
    int n = getN(k,poss);
    
    for(auto& v : ranges)
    {
        int v1 = v[0];
        int v2 = n + v[1];
        
        cout << v1 << '\n';
        cout << v2 << '\n';
        
        if(v1 > v2 ||
          v2 > n ||
          v1 > n)
        {
            answer.push_back(-1);
            continue;
        }
        
        
        if(v1 == v2)
        {
            answer.push_back(0.0);
        }
        else
        {
            double value = 0.0;
            for(int i = v1; i < v2;i++)
            {
                value += poss[i];
            }
            answer.push_back(value);
        }
        
    }
    
    return answer;
}