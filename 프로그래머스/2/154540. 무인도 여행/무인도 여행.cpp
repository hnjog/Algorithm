#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void recur(vector<string>& maps, vector<int>& answer, int& now, int y, int x)
{
    if(y < 0 || y >= maps.size() ||
      x < 0 || x >= maps[0].size())
        return;
    
    if(maps[y][x] == 'X' ||
      maps[y][x] == '0')
        return;
    
    now += (maps[y][x] - '0');
    maps[y][x] = '0';
    
    recur(maps,answer,now,y-1,x);
    recur(maps,answer,now,y+1,x);
    recur(maps,answer,now,y,x-1);
    recur(maps,answer,now,y,x+1);
}

void DFS(vector<string>& maps, vector<int>& answer)
{
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m;j++)
        {
            if(maps[i][j] == 'X' ||
              maps[i][j] == '0')
                continue;
            
            int v = 0;
            recur(maps,answer,v,i,j);
            answer.push_back(v);
        }
    }
    
}

vector<int> solution(vector<string> maps) 
{
    vector<int> answer;
    DFS(maps,answer);
    if(answer.empty())
        answer.push_back(-1);
    
    sort(answer.begin(),answer.end());
    return answer;
}