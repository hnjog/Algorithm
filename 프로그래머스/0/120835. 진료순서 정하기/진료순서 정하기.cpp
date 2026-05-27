#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<pair<int, int>> vec;

    int size = emergency.size();

    for (int i = 0; i < size; i++)
    {
        vec.push_back(make_pair(i, emergency[i]));
        answer.push_back(0);
    }

    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) -> bool {return a.second > b.second; });

    for (int i = 0; i < size; i++)
    {
        answer[vec[i].first] = i + 1;
    }

    return answer;
}