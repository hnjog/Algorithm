#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long answer = -1;
    long long minV = food_times[0];
    long long sumV = 0;
    const int fSize = food_times.size();

    for (int f : food_times)
    {
        sumV += f;
        if (f < minV)
            minV = f;
    }

    long long checkM = minV * fSize;
    
    if (sumV <= k)
    {
        return -1;
    }

    if (checkM >= k)
    {
        answer = (k % fSize) + 1;
        return answer;
    }

    k -= checkM;

    struct cmp {
        bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b) {
            if (a.second == b.second)
                return a.first > b.first;

            return a.second > b.second;
        }
    };

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp > q;
    for (int i = 0; i < fSize; i++)
    {
        if (food_times[i] - minV <= 0)
            continue;

        q.push({ i + 1,food_times[i] - minV });
    }

    minV = 0;
    while (q.empty() == false)
    {
        auto p = q.top();
        int prevM = minV;
        minV = p.second;
        checkM = (long long)(minV - prevM) * q.size(); // 이전과 값이 같았다면 여기서 0 나오므로 일단 중복은 상관 x
        if (k < checkM)
        {
            int idx = k % q.size();

            // 이 시점에서 first 기준으로 다시 정렬이 필요함
            priority_queue<pair<long long, long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;

            while (q.empty() == false)
            {
                pq.push(q.top());
                q.pop();
            }

            while (idx > 0)
            {
                pq.pop();
                idx--;
            }

            answer = pq.top().first;

            return answer;
        }
        else
        {
            k -= checkM;
        }

        q.pop();

    }

    return answer;
}