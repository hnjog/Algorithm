#include<iostream>

using namespace std;

struct Point {
    long long x, y;
};

bool isSamePoint(Point& p1, Point& p2)
{
    if (p1.x == p2.x &&
        p1.y == p2.y)
        return true;

    return false;
}

int orientation(Point p, Point q, Point r)
{
    long long val1 = (q.y - p.y) * (r.x - q.x);
    long long val2 = (q.x - p.x) * (r.y - q.y);
    if (val1 == val2) 
        return 0;

    return (val1 > val2) ? 1 : 2;
}

bool onSegment(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // 일반적인 경우
    if (o1 != o2 && o3 != o4)
        return true;

    // 콜리니어 점 처리
    if (o1 == 0 && onSegment(p1, p2, q1)) 
        return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) 
        return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) 
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) 
        return true;

    return false; // 교차하지 않음
}

int main()
{
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;
    cout << doIntersect(p1, p2, p3, p4) ? 1 : 0;
}