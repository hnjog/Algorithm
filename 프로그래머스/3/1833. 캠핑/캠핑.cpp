#include <vector>
#include<algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    
    // x 순으로 
    sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
        if (a[0] == b[0])
            return a[1] < b[1];

        return a[0] < b[0];
        });

    const int dSize = data.size();

    for (int i = 0; i < dSize; i++)
    {
        int x = data[i][0];
        int y = data[i][1];

        for (int j = i + 1; j < dSize; j++)
        {
            int x2 = data[j][0];
            int y2 = data[j][1];

            int minx = min(x, x2);
            int miny = min(y, y2);
            int maxx = max(x, x2);
            int maxy = max(y, y2);

            // 넓이 0
            if (minx == maxx || miny == maxy)
                continue;

            bool isIn = false;
            for (int k = i + 1; k < j; k++)
            {
                int x3 = data[k][0];
                int y3 = data[k][1];
                if (x3 > minx && x3 < maxx &&
                    y3 > miny && y3 < maxy)
                {
                    isIn = true;
                    break;
                }
            }

            if (isIn == false)
                answer++;
        }

    }

    return answer;
}