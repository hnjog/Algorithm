#include <vector>

using namespace std;

bool isRightLevel(vector<int>& diffs, vector<int>& times, long long limit, int nowLevel)
{
    // nowLevel 내에 limit 통과 가능한지 테스트
    long long nowTime = times[0];
    int timePrev = times[0];
    
    int dSize = diffs.size();
    
    for(int i = 1; i < dSize;i++)
    {
        int nowdiff = diffs[i];
        int nowtuse = times[i];
        
        if(nowLevel < nowdiff)
        {
            nowTime += (nowdiff - nowLevel) * (timePrev + nowtuse);
        }
        
        nowTime += nowtuse;
        timePrev = nowtuse;
        
        if(nowTime > limit)
            return false;
    }
    
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int low = 1, high = 100000;
    int mid = 0;
    
    while(low < high)
    {
        mid = (low + high)/2;
        
        if(isRightLevel(diffs,times,limit,mid))
        {
            // 현재 level은 충분하니
            // 더 작은 레벨 탐색
            high = mid;
        }
        else
        {
            // 현재 level이 너무 작음
            low = mid + 1;
        }
    }
    
    answer = low;
    
    return answer;
}