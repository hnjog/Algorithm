#include<vector>
#include<unordered_set>

using namespace std;

void dfs(int n, int& answer, vector<int>& arr, unordered_set<int>& us)
{
    if (n == arr.size())
    {
        answer++;
        return;
    }

    int b = arr.back();

    for (int i = 0; i < n; i++)
    {
        // 이미 있는 경우
        if (us.find(i) != us.end())
            continue;

        int idx = arr.size();
        bool isCheck = true;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] - idx == i || arr[j] + idx == i)
            {
                isCheck = false;
                break;
            }

            idx--;
        }

        if (isCheck == false)
            continue;

        us.insert(i);
        arr.push_back(i);
        dfs(n, answer, arr, us);
        arr.pop_back();
        us.erase(i);
    }
}

int solution(int n) {
    int answer = 0;

    vector<int> arr;
    unordered_set<int> us;
    for (int i = 0; i < n; i++)
    {
        us.insert(i);
        arr.push_back(i);
        dfs(n, answer, arr,us);
        arr.pop_back();
        us.erase(i);
    }

    return answer;
}