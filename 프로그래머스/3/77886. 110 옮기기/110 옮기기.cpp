#include <string>
#include <vector>
#include<math.h>

using namespace std;

bool find110(const string& s, int startInd)
{
    if (s.size() <= startInd + 2)
        return false;

    if (s[startInd] == '1' &&
        s[startInd + 1] == '1' &&
        s[startInd + 2] == '0')
        return true;

    return false;
}

bool find111(const string& s, int startInd)
{
    if (s.size() <= startInd + 2)
        return false;

    if (s[startInd] == '1' &&
        s[startInd + 1] == '1' &&
        s[startInd + 2] == '1')
        return true;

    return false;
}

string func(string s)
{
    const int sSize = s.size();
    if (sSize <= 2)
        return s;

    // 1. 110을 전부 제거하기
    int deleteCount = 0;
    string temp = s;
    int pos = 0;
    while ((pos = temp.find("110", pos)) != string::npos)
    {
        temp.erase(pos, 3);
        deleteCount++;
        pos = max(pos - 3,0);
    }

    // 2. 삽입을 할 위치 찾기
    int lastZeroPos = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == '0')
        {
            lastZeroPos = i + 1;
        }
    }

    string temp2 = temp.substr(0, lastZeroPos);
    string temp3 = temp.substr(lastZeroPos, temp.size() - lastZeroPos);

    for (int i = 0; i < deleteCount; i++)
    {
        temp2 += "110";
    }

    return temp2 + temp3;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (auto str : s)
    {
        answer.push_back(func(str));
    }

    return answer;
}