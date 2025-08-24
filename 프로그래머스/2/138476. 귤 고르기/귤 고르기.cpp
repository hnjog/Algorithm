#include <vector>
#include<map>
#include<algorithm>
#include<iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;

    for (int t : tangerine)
    {
        if (m.find(t) == m.end())
            m[t] = 0;

        m[t] += 1;
    }

    vector<pair<int, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    int sum = 0;

    for (auto& p : v)
    {
        answer++;
        sum += p.second;
        if (sum >= k)
            break;
    }

    return answer;
}