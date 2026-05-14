#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;

    int wsize = weak.size();

    for (int i = 0; i < wsize - 1; i++) {
        weak.push_back(weak[i] + n);
    }

    sort(dist.begin(), dist.end());

    for (int i = 0; i < wsize; i++)
    {
        do {
            int count = 1;
            int range = weak[i] + dist[count - 1];

            for (int idx = i; idx < i + wsize; idx++)
            {
                if (range < weak[idx])
                {
                    count++;

                    if (count > dist.size())
                        break;

                    range = weak[idx] + dist[count - 1];
                }
            }

            answer = min(answer, count);
        } while (next_permutation(dist.begin(), dist.end()));
    }

    if (answer > dist.size())
        return -1;

    return answer;
}