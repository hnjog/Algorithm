#include <string>
#include <vector>
#include<numeric>
#include<math.h>
#include<queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    long long sum = accumulate(works.begin(), works.end(), 0) - n;

    // 남은 시간내에 끝나서 야근 안해도 됨
    if (sum <= 0)
        return 0;

    // 여기서 부터는 야근임
    const int wSize = works.size();

    priority_queue<int, vector<int>, less<int>> pq;
    
    for (auto w : works)
    {
        pq.push(w);
    }

    while (n > 0)
    {
        int t = pq.top();
        pq.pop();
        int dist = t - pq.top() + 1;

        if (dist > n)
        {
            dist = n;
        }
        
        t -= dist;
        n -= dist;

        pq.push(t);
    }


    while (pq.empty() == false)
    {
        answer += pow(pq.top(), 2);
        pq.pop();
    }

    return answer;
}
