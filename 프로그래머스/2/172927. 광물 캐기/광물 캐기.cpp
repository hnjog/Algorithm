#include <string>
#include <vector>

using namespace std;

enum
{
    e_Dia = 0,
    e_Iron = 1,
    e_Ston = 2,
    e_Count,
};

// 곡괭이 / 광물 피로도 코스트
const int mineCost[e_Count][e_Count] = { {1,1,1},{5,1,1},{25,5,1} };
const int pixCount = 5;

// 곡괭이로 다음 5개 캘 예상 코스트
int expectValue(int pix, vector<string>& minerals,int idx)
{
    int nowCount = pixCount;
    const int mSize = minerals.size();

    int result = 0;

    for (int i = idx; i < mSize; i++)
    {
        if (nowCount == 0)
            break;

        if (minerals[i] == "diamond")
        {
            result += mineCost[pix][e_Dia];
        }
        else if (minerals[i] == "iron")
        {
            result += mineCost[pix][e_Iron];
        }
        else
        {
            result += mineCost[pix][e_Ston];
        }

        nowCount--;
    }

    return result;
}

void backTrack(vector<int>& picks, vector<string>& minerals, int idx, int& answer, int nowSum)
{
    int mSize = minerals.size();
    if (idx >= mSize)
    {
        if (nowSum < answer ||
            answer == 0)
        {
            answer = nowSum;
        }

        return;
    }

    bool anyOnecheck = true;
    for (int i = 0; i < e_Count; i++)
    {
        if (picks[i] == 0)
            continue;

        anyOnecheck = false;
        int sum = nowSum;
        int value = expectValue(i, minerals, idx);

        sum += value;
        picks[i]--;

        backTrack(picks, minerals, idx + pixCount, answer, sum);

        picks[i]++;
        sum -= value;
    }

    if (anyOnecheck)
    {
        if (nowSum < answer ||
            answer == 0)
        {
            answer = nowSum;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    backTrack(picks, minerals, 0, answer, 0);
    return answer;
}