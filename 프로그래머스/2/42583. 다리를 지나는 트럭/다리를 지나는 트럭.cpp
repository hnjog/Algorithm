#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weightSum = 0;
    queue<int> waitingQ;
    queue<pair<int, int>> passingQ; // 무게 , 들어간 시점

    for (int i = 0; i < truck_weights.size(); i++)
    {
        waitingQ.push(truck_weights[i]);
    }

    while (waitingQ.empty() == false || passingQ.empty() == false)
    {
        answer++;

        if (passingQ.empty() == false)
        {
            pair<int, int> f = passingQ.front();

            if (f.second + bridge_length <= answer)
            {
                passingQ.pop();
                weightSum -= f.first;
            }
        }

        if (waitingQ.empty() == false)
        {
            int wei = waitingQ.front();

            if (wei + weightSum <= weight)
            {
                waitingQ.pop();
                passingQ.push(make_pair(wei, answer));
                weightSum += wei;
            }
        }
    }

    return answer;
}