#include <string>
#include <vector>
#include<math.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int height = triangle.size();

    for (int i = height - 2; i >= 0; i--)
    {
        int wide = triangle[i].size();

        for (int j = 0; j < wide; j++)
        {
            int& originV = triangle[i][j];

            // 아래쪽의 vector는 현재 vector의 size보다 하나 더 크므로
            originV += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    return triangle[0][0];
}