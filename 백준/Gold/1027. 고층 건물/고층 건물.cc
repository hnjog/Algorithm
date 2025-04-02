#include<iostream>
#include<vector>

using namespace std;

struct Point {
    long long x, y;
};

int orientation(Point p, Point q, Point r)
{
    long long val1 = (q.y - p.y) * (r.x - q.x);
    long long val2 = (q.x - p.x) * (r.y - q.y);
    if (val1 == val2)
        return 0;

    return (val1 > val2) ? 1 : -1;
}

int main()
{
    int n;
    cin >> n;
    vector<Point> pv;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pv.push_back({i,t});
    }
    vector<int> counts(n,0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            bool check = true;
            for (int k = i + 1; k < j; k++)
            {
                if (orientation(pv[j], pv[i], pv[k]) >= 0)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                counts[i]++;
                counts[j]++;
            }
        }
    }

    int maxV = 0;
    for (int c : counts)
    {
        if (c > maxV)
            maxV = c;
    }

    cout << maxV;
}