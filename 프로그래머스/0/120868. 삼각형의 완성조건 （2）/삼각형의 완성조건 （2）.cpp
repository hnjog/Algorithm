#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(), sides.end());
    
    // sides[1] 이 제일 큰 변인 경우
    // sides[0] + x > sides[1]보다 작은 변의 개수를 구해야 함
    // 이 때 x는 sides[1]보다는 작음
    for(int i = 1; i < sides[1];i++)
    {
        if(sides[0] + i > sides[1])
        {
            answer++;
        }
    }
    
    // x가 제일 큰 변인 경우
    // sides[0] + sides[1] > x인 변의 개수를 구해야 함
    // 이 때 x는 sides[1]보다 큼
    for(int i = sides[1]; i < sides[0] + sides[1];i++)
    {
        if(sides[0] + sides[1] > i)
        {
            answer++;
        }
    }
    
    
    return answer;
}