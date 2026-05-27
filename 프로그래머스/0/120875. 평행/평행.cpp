#include <string>
#include <vector>
#include <math.h>

using namespace std;

double getSlope(int x1, int x2, int y1, int y2)
{
    if(y2 == y1)
        return 0.0;
    
    double result = 0.0;
    
    result = abs((double)(x1 - x2) /(y1 - y2));
    
    return result;
}

double eps = 1e-9;
bool isSameDouble(double d1, double d2)
{
    return abs(d1 - d2) < eps;
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    // 선분의 기울기
    // abs((x1 - x2) / (y1-y2) );
    // 이것과 나머지 점 2개의 기울기를 비교해야 함
    for(int i = 0; i < dots.size();i++)
    {
        for(int j = i + 1; j < dots.size();j++)
        {
            // x 기준 기울기
            double s1, s2;
            
            s1 = getSlope(dots[i][0],dots[j][0],dots[i][1],dots[j][1]);
            int k = - 1,q = -1;
            for(int u = 0; u < dots.size(); u++)
            {
                if(u == i || u == j)
                    continue;
                
                if(k == -1)
                    k = u;
                else if(q == -1)
                    q = u;
            }
            
            s2 = getSlope(dots[k][0],dots[q][0],dots[k][1],dots[q][1]);
            
            if(isSameDouble(s1,s2))
                return 1;
            
            // y 기준 기울기
            s1 = getSlope(dots[i][1],dots[j][1],dots[i][0],dots[j][0]);
            s2 = getSlope(dots[k][1],dots[q][1],dots[k][0],dots[q][0]);
            
            if(isSameDouble(s1,s2))
                return 1;
        }
    }
    
    return answer;
}