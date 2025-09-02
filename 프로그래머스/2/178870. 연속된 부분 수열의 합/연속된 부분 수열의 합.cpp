#include <vector>
#include <limits.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int sSize = sequence.size();

    int left = 0;
    int right = 0;
    int length = INT_MAX;
    int sum = sequence[0];

    while (right < sSize)
    {
        if (sum == k)
        {
            int nowLen = right - left;
            if (nowLen < length)
            {
                length = nowLen;
                answer[0] = left;
                answer[1] = right;
            }
            right++;
            if (right >= sSize)
                break;
            sum += sequence[right];
        }
        else if (sum < k)
        {
            right++;
            if (right >= sSize)
                break;
            sum += sequence[right];
        }
        else
        {
            sum -= sequence[left];
            left++;
            if (left > right)
                break;
        }
    }

    return answer;
}