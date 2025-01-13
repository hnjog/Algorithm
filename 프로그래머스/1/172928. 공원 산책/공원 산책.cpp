#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer(2,0);
    int h = park.size();
    int w = park[0].size();
    for(int i = 0; i <h;i++)
    {
        for(int j = 0; j < w;j++)
        {
            if(park[i][j] == 'S')
            {
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    
    for(string s : routes)
    {
        char dir = s[0];
        int val = int(s[2] - '0');
        
        if(dir == 'N')
        {
            if(answer[0] -val < 0)
                continue;
            
            bool isNotSuccess = false;
            for(int i = answer[0]; i >= answer[0] - val;i--)
            {
                if(park[i][answer[1]] == 'X')
                {
                    isNotSuccess = true;
                    break;
                }
            }
            
            if(isNotSuccess)
                continue;
            
            answer[0] -= val;
        }
        else if(dir == 'S')
        {
            if(answer[0] + val >= h)
                continue;
            
            bool isNotSuccess = false;
            for(int i = answer[0]; i <= answer[0] + val;i++)
            {
                if(park[i][answer[1]] == 'X')
                {
                    isNotSuccess = true;
                    break;
                }
            }
            
            if(isNotSuccess)
                continue;
            
            answer[0] += val;
        }
        else if(dir == 'W')
        {
            if(answer[1] - val < 0)
                continue;
            
            bool isNotSuccess = false;
            for(int i = answer[1]; i >= answer[1] - val;i--)
            {
                if(park[answer[0]][i] == 'X')
                {
                    isNotSuccess = true;
                    break;
                }
            }
            
            if(isNotSuccess)
                continue;
            
            answer[1] -= val;
        }
        else if(dir == 'E')
        {
            if(answer[1] + val >= w)
                continue;
            
            bool isNotSuccess = false;
            for(int i = answer[1]; i <= answer[1] + val;i++)
            {
                if(park[answer[0]][i] == 'X')
                {
                    isNotSuccess = true;
                    break;
                }
            }
            
            if(isNotSuccess)
                continue;
            
            answer[1] += val;
        }
    }
    
    return answer;
}