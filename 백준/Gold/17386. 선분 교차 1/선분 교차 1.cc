#include<iostream>

using namespace std;

struct Point {
    long x, y;
};

long orientation(Point p, Point q, Point r)
{
    long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) 
        return 0;

    return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{
    long o1 = orientation(p1, q1, p2); // 선분 1 에서 점 p2
    long o2 = orientation(p1, q1, q2); // 선분 1 에서 점 q2
    long o3 = orientation(p2, q2, p1);
    long o4 = orientation(p2, q2, q1);
    if (o1 == 0 ||
        o2 == 0 ||
        o3 == 0 ||
        o4 == 0)
        return false;
    

    // o1 != o2 : 한 선분에서 하나는 자신의 왼쪽, 하나는 자신의 오른쪽에 있는 결과이므로
    // 양측 다 그렇다면 두 선분이 교차하고 있다는 말
    if (o1 != o2 && o3 != o4) 
        return true;

    return false;
}

int main()
{
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;
    cout << doIntersect(p1, p2, p3, p4) ? 1 : 0;
}