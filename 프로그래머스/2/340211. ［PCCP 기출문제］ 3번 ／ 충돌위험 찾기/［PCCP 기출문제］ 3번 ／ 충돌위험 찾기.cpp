#include <vector>
#include <queue>
#include <set>

using namespace std;

struct infos
{
    int y = 0,x = 0;
    int nowidx = 0;
    vector<pair<int,int>> tPoss;
};

bool movePos(vector<vector<int>>& maps, infos& now)
{
    if(now.y == now.tPoss[now.nowidx].first &&
      now.x == now.tPoss[now.nowidx].second)
    {
        now.nowidx++;
    }
        
    maps[now.y][now.x]--;
    
    if(now.nowidx >= now.tPoss.size())
    {
        return true;
    }
    
    
    if(now.y > now.tPoss[now.nowidx].first)
    {
        now.y--;
    }
    else if(now.y < now.tPoss[now.nowidx].first)
    {
        now.y++;
    }
    else
    {
        if(now.x > now.tPoss[now.nowidx].second)
        {
            now.x--;
        }
        else if(now.x < now.tPoss[now.nowidx].second)
        {
            now.x++;
        }
    }
    
    maps[now.y][now.x]++;
    return false;
}

void func(vector<vector<int>>& points, vector<vector<int>>& routes,vector<vector<int>>& maps, int& answer)
{
    int rSize = routes.size() - 1;
    queue<infos> nows;
    set<pair<int,int>> ns;
    for(auto& v : routes)
    {
        infos n;
        n.y = points[v[0]-1][0]-1;
        n.x = points[v[0]-1][1]-1;
        
        n.tPoss.push_back({n.y,n.x});
        
        for(int i = 1; i < v.size();i++)
        {
            int nty = points[v[i]-1][0]-1;
            int ntx = points[v[i]-1][1]-1;
            n.tPoss.push_back({nty,ntx});
        }
        
        maps[n.y][n.x]++;
        ns.insert({n.y,n.x});
        nows.push(n);
    }
    
    for(const auto& p : ns)
    {
        if(maps[p.first][p.second] > 1)
        {
            answer++;
        }
    }
    
    int time = 1;
    
    while(nows.size() >= 2)
    {
        int s = 0;
        ns.clear();
        
        for(int i = 0; i <= rSize; i++)
        {
            infos p = nows.front();
            nows.pop();

            if(movePos(maps,p))
            {
                s++;
                continue;
            }
            
            ns.insert({p.y,p.x});
            nows.push(p);
        }
        
        for(const auto& p : ns)
        {
            if(maps[p.first][p.second] > 1)
            {
                answer++;
            }
        }
        
        time++;
        rSize -= s;
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    vector<vector<int>> maps(101,vector<int>(101,0));
    
    func(points,routes,maps,answer);
    
    return answer;
}