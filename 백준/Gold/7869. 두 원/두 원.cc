#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// d : 두 점간의 거리
double overlapArea(double r1, double r2, double d) 
{
    if (d >= r1 + r2) 
    {
        return 0.0; // 두 원이 겹치지 않음
    }

    if (d <= abs(r1 - r2)) 
    {
        // 한 원이 다른 원 안에 완전히 포함됨
        return M_PI * min(r1, r2) * min(r1, r2);
    }

    double part1 = r1 * r1 * acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
    double part2 = r2 * r2 * acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
    double part3 = 0.5 * sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2));

    return part1 + part2 - part3;
}

int main() 
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    cout << fixed << setprecision(3);
    cout << overlapArea(r1, r2, distance);
}
