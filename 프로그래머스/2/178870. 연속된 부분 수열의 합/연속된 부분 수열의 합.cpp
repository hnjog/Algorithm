#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int sSize = sequence.size();

    for (int i = 0; i < sSize; i++)
    {
        // 길이가 0
        if (sequence[i] == k)
        {
            answer.push_back(i);
            answer.push_back(i);
            return answer;
        }
    }

    int sum = 0;
    int left = 0;
    int shortLength = 10000001;
    // 투 포인터
    for (int r = 0; r < sSize; r++)
    {
        // 애초에 r까지의 합이 작으면 아래를 구할 필요가 없으므로
        sum += sequence[r];

        // 목표값보다 크다면 왼쪽에서 값을 빼주어 조정한다
        while (sum > k)
        {
            sum -= sequence[left];
            left++;
        }

        if (sum == k &&
            r - left < shortLength)
        {
            answer.clear();
            answer.push_back(left);
            answer.push_back(r);
            shortLength = r - left;
        }
    }

    return answer;
}