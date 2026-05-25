#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool IsPrime(int value)
{
    if(value <= 1)
        return false;
    
    if(value < 4)
        return true;
    
    for(int i = 2; i <= value / 2;i++)
    {
        if(value % i == 0)
            return false;
    }
    
    return true;
}

void dfs(const string& origin, vector<bool>& visited,int now, string& temp,unordered_set<int>& us)
{
    if(temp.size() > 0)
    {
        int s = stoi(temp);
        if(IsPrime(s))
        {
            us.insert(s);
        }    
    }
    
    int oSize = origin.size();
    
    for(int i=0;i<oSize;i++)
    {
        if(visited[i])
            continue;
        
        visited[i] = true;
        temp.push_back(origin[i]);
        dfs(origin,visited,i,temp,us);
        temp.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    int best = 0;
    unordered_set<int> us;
    for(int i=0;i<numbers.size();i++)
    {
        vector<bool> visited(numbers.size());
        string temp = "";
        dfs(numbers,visited,i,temp,us);    
        if(us.size() > best)
            best = us.size();
    }
    
    return best;
}