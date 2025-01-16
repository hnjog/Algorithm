#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

const int dirx[4] = {-1,0,1,0};
const int diry[4] = {0,1,0,-1};

vector<vector<int>> l;
map<int,int> m;

void bfs(int idx, int x, int y)
{
    int w = l.size();
    int h = l[0].size();
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    int sum = 0;
    
    while(q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        
        int nowx = p.first;
        int nowy = p.second;
        
        if(nowx < 0 || nowx >=w||
          nowy<0 || nowy >= h)
            continue;
        
        if(l[nowx][nowy] != 1)
            continue;
        
        l[nowx][nowy] = idx;
        sum++;
        
        for(int i = 0; i < 4;i++)
        {
            int nextx = nowx + dirx[i];
            int nexty = nowy + diry[i];
            
            q.push({nextx,nexty});
        }
    }
    
    m[idx] = sum;
}

void setup()
{
    int idx = 2;
    int w = l.size();
    int h = l[0].size();
    
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h;j++)
        {
            if(l[i][j] == 1)
            {
                bfs(idx,i,j);
                idx++;
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    l = land;

    setup();
    
    int w = l.size();
    int h = l[0].size();
    set<int> vis;
    
    for(int i = 0; i < h; i++)
    {
        int value = 0;
        vis.clear();
        for(int j = 0; j < w;j++)
        {
            if(l[j][i] == 0)
                continue;
            
            if(vis.find(l[j][i]) != vis.end())
                continue;
            
            vis.insert(l[j][i]);
            value += m[l[j][i]];
        }
        
        if(value > answer)
            answer = value;
    }
    
    return answer;
}