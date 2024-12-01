#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int sv = min(n,m);
    int minV = 1;
    for(int i = 2; i <= sv;i++)
    {
        if(m% i == 0 &&
          n % i == 0)
            minV = i;
    }
    
    answer.push_back(minV);
    
    int mv = max(n,m);
    int maxV = n * m;
    
    for(int i = mv;i <= maxV;i++)
    {
        if(i % n == 0 &&
          i % m == 0)
        {
            answer.push_back(i);
            break;
        }
    }
    
    return answer;
}