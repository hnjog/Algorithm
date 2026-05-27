#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;

    int start = total / 2 + num;

    while (true)
    {
        int sum = 0;
        for (int i = start - num + 1; i <= start; i++)
        {
            sum += i;
            if (sum > total)
            {
                break;
            }
        }

        if (sum == total)
        {
            for (int i = start - num + 1; i <= start; i++)
            {
                answer.push_back(i);
            }
            break;
        }

        start--;
        answer.clear();
    }

    return answer;
}