#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<pair<int,int>> stacks;
    
    int pSize = prices.size();
    stacks.reserve(pSize);

    for (int i = 0; i < pSize; i++)
    {
        answer.push_back(0);
    }

    for (int i = 0; i < pSize;i++)
    {
        for (int j = 0; j < stacks.size(); j++)
        {
            pair<int, int>& p = stacks[j];
            answer[p.second] += 1;
        }

        while (stacks.empty() == false &&
            stacks.back().first > prices[i])
        {
            stacks.pop_back();
        }

        stacks.push_back(make_pair(prices[i], i));
    }

    return answer;
}