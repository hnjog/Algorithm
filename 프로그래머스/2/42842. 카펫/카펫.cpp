#include <vector>

using namespace std;

int GetBrown(int sum, int width)
{
    int h = sum / width;
    return width * 2 + h * 2 - 4;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    for (int i = sum / 2; i >= 3; i--)
    {
        if (sum % i == 0 &&
            GetBrown(sum, i) == brown)
        {
            int j = sum / i;
            if (i < j)
            {
                swap(i, j);
            }

            answer.push_back(i);
            answer.push_back(j);
            break;
        }
    }

    return answer;
}