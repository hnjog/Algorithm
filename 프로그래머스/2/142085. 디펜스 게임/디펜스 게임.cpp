#include <vector>
#include<queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int eSize = enemy.size();
    if (k >= eSize)
        return eSize;

    int answer = 0;

    priority_queue<int> pq;

    for (int i = 0; i < eSize; i++)
    {
        pq.push(enemy[i]);
        n -= enemy[i];
        if (n < 0)
        {
            if (k > 0)
            {
                n += pq.top();
                pq.pop();
                k--;
            }
            else
            {
                break;
            }
        }
        answer = i + 1;
    }

    return answer;
}