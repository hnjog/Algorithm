#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    // answer[0]의 범위는 1 ~ s / 2까지
    int s = brown / 2 + 2;

    for (int i = s / 2; i > 0; i--)
    {
        if (i * (s - i) == sum)
        {
            answer.push_back(i);
            answer.push_back(s - i);
            break;
        }
    }

    if (answer[0] < answer[1])
    {
        swap(answer[0], answer[1]);
    }

    return answer;
}
