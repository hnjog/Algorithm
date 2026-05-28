#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<int> priorities, int location) {
    int answer = 1;

    int n = priorities.size();
    queue<pii> q;
    
    for (int i = 0; i < n; i++)
    {
        q.push({ priorities[i],i });
    }

    sort(priorities.begin(), priorities.end(), greater<int>());

    int pidx = 0;
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();

        if (p.first == priorities[pidx])
        {
            pidx++;

            if (p.second == location)
                break;

            answer++;

        }
        else
        {
            q.push(p);
        }
    }
    return answer;
}