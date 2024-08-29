#include <vector>
#include <unordered_map>

using namespace std;


int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> rightMap;

    for (int i = 0; i < topping.size(); i++)
    {
        if (rightMap.find(topping[i]) == rightMap.end())
            rightMap[topping[i]] = 0;

        rightMap[topping[i]]++;
    }

    unordered_map<int, int> leftMap;

    for (int i = 0; i < topping.size(); i++)
    {
        int topp = topping[i];

        if (leftMap.find(topp) == leftMap.end())
            leftMap[topp] = 0;

        leftMap[topp]++;

        if (rightMap.find(topp) != rightMap.end())
        {
            rightMap[topp]--;
            if (rightMap[topp] == 0)
            {
                rightMap.erase(topp);
            }
        }

        if (leftMap.size() == rightMap.size())
            answer++;
    }

    return answer;
}