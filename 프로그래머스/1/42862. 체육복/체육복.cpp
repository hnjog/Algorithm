#include <set>
#include <vector>
#include<algorithm>
#include<math.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    set<int> ls(lost.begin(),lost.end());
    set<int> rs(reserve.begin(),reserve.end());
    
    // 자신의 체육복을 잃어버렸으나 여벌이 있다면 우선 제거
    for(auto it = ls.begin(); it != ls.end(); it++)
    {
        if(rs.find(*it) != rs.end())
        {
            ls.erase(*it);
            rs.erase(*it);
        }
    }
    
    for(auto it = ls.begin(); it != ls.end();it++)
    {
        bool bDeleted = false;
        for(auto it2 = rs.begin();it2 != rs.end();it2++)
        {
            if(abs(*it - *it2) <= 1)
            {
                bDeleted = true;
                rs.erase(*it2);
                break;
            }
        }
        
        if(bDeleted == false)
            answer--;
        
    }

    return answer;
}