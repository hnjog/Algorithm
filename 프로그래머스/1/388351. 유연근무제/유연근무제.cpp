#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int sSize = schedules.size();

    for(int i =0;i< sSize;i++)
    {
        int tv = schedules[i];
        int mValue = tv % 100;
        int hValue = (tv - mValue) / 100;
        
        schedules[i] = hValue * 60 + mValue;
    }
    cout << '\n';
    for(int i = 0; i < sSize;i++ )
    {
        for(int j = 0; j < 7;j++)
        {
            int tv = timelogs[i][j];
            int mValue = tv % 100;
            int hValue = (tv - mValue) / 100;
            timelogs[i][j] = hValue * 60 + mValue;
        }
    }
    
    for(int i = 0; i < sSize; i++)
    {
        int count = 0;
        
        for(int j = 0; j < 7;j++)
        {
            if((startday + j - 1) % 7 + 1 >= 6)
                continue;
            
            if(timelogs[i][j] <= schedules[i] + 10)
                count++;
        }
        
        if(count == 5)
            answer++;
    }
    
    return answer;
}