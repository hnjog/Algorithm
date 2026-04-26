#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int FindParent(vector<int>& pv, int x)
{
    if (pv[x] == x)
        return x;

    return pv[x] = FindParent(pv, pv[x]);
}

bool Union(vector<int>& pv,int a,int b)
{
    a = FindParent(pv, a);
    b = FindParent(pv, b);

    if (a == b)
        return false;

    pv[a] = b;

    return true;
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> pv(n);
    for (int i = 0; i < n; i++)
        pv[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (computers[i][j] == 1)
                Union(pv, i, j);
        }
    }

    unordered_set<int> us;
    us.reserve(n);

    for (int p : pv)
    {
        us.insert(FindParent(pv,p));
    }

    return us.size();
}