#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
    bool operator()(const pii& a, const pii& b)
    {
        if (a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pii, vector<pii>, Compare> q;

    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b)->bool {
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0]; });

    int jSize = jobs.size();

    int time = 0;
    int index = 0;

    while (q.empty() == false || index < jSize)
    {
        // 비어 있는 경우
        // 반드시 index에 해당하는 first가 
        // 현재 time보다 클 수 밖에 없음
        if (q.empty())
        {
            q.push(make_pair(jobs[index][0], jobs[index][1]));
            index++;
            continue;
        }


        // 하나 빼주고 이녀석 기준으로 진행
        pii p = q.top();
        q.pop();
        // 현재 시점에 들어왔으므로 진행도 저장
        if (time < p.first)
            time = p.first;
        
        int endTime = time + p.second;
        answer += (endTime - p.first);

        while (time < endTime)
        {
            if (index < jSize && time >= jobs[index][0])
            {
                q.push(make_pair(jobs[index][0], jobs[index][1]));
                index++;
            }

            time++;
        }
    }

    answer /= jSize;

    return answer;
}
