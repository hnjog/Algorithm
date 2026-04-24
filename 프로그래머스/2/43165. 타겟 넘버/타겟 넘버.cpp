#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, int target, int idx, int nowSum, int& count)
{
    int ns = numbers.size();

    if (idx >= ns)
    {
        if (nowSum == target)
            count++;

        return;
    }

    dfs(numbers, target, idx + 1, nowSum + numbers[idx], count);
    dfs(numbers, target, idx + 1, nowSum - numbers[idx], count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}