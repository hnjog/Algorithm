#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> que;

    int pSize = priorities.size();

    for (int i = 0; i < pSize; i++)
    {
        que.push(make_pair(priorities[i], i));
    }

    sort(priorities.begin(), priorities.end());

    while (que.empty() == false)
    {
        pair<int, int> a = que.front();
        que.pop();

        if (priorities.back() == a.first)
        {
            answer++;

            if (a.second == location)
            {
                break;
            }

            priorities.pop_back();
        }
        else
        {
            que.push(a);
        }
    }

    return answer;
}