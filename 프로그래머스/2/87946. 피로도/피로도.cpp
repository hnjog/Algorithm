#include <vector>

using namespace std;

void Recur(const vector<vector<int>>& dungeons, int now, int count, int remainK, vector<bool>& visit, int& answer)
{
    if (count > answer)
    {
        answer = count;
    }

    int dsize = dungeons.size();

    if (count >= dsize)
        return;

    for (int i = 0; i < dsize; i++)
    {
        if (visit[i] == true)
            continue;

        if (dungeons[i][0] > remainK)
            continue;

        visit[i] = true;
        Recur(dungeons, i, count + 1, remainK - dungeons[i][1], visit, answer);
        visit[i] = false;
    }
}

void StartRecur(const vector<vector<int>>& dungeons,int k, int& answer)
{
    int dsize = dungeons.size();
    vector<bool> visit(dsize, false);

    for (int i = 0; i < dsize; i++)
    {
        if (dungeons[i][0] > k)
            continue;

        visit[i] = true;
        Recur(dungeons, i, 1, k - dungeons[i][1], visit, answer);
        visit[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    StartRecur(dungeons,k, answer);
    return answer;
}