#include <string>
#include <vector>
#include<sstream>
#include<unordered_map>

using namespace std;

struct SingInfo
{
    string singFlot; // 멜로디
    int startTime; // 시작 시간
    int singTime;  // 총 시간
    int flotCount; // 노래 총 음 수 (singFlot.size())
    int idx;
};

int getTime(const string& time)
{
    string hour = string(time.begin(),time.begin() + 2);
    string minu = string(time.begin() + 3, time.begin() + 5);

    return stoi(hour) * 60 + stoi(minu);
}

bool isInMelody(const string& m, const SingInfo& si)
{
    string melo = "";

    // 노래 시간이 매우 짧은 경우
    if (si.flotCount > si.singTime)
    {
        melo = string(si.singFlot.begin(), si.singFlot.begin() + si.singTime);
    }
    else if(si.flotCount < si.singTime)
    {
        int t = si.singTime / si.flotCount;

        for (int i = 0; i < t; i++)
        {
            melo += si.singFlot;
        }

        int remainTime = si.singTime % si.flotCount;
        melo += string(si.singFlot.begin(), si.singFlot.begin() + remainTime);
    }
    else
    {
        melo = si.singFlot;
    }

    size_t s = melo.find(m);
    if (s != string::npos)
        return true;

    return false;
}

string sharpCheck(string target)
{
    size_t s = target.find("#");
    if (s == string::npos)
        return target;

    string ret = "";
    for (int i = 0; i < target.size(); i++)
    {
        if (target[i] == '#')
        {
            ret.back() = tolower(ret.back());
        }
        else
        {
            ret += target[i];
        }
    }

    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    m = sharpCheck(m);

    unordered_map<string, SingInfo> singMap;

    int idx = 0;
    for (string& music : musicinfos)
    {
        stringstream ss(music);
        string temp;
        vector<string> tokens;
        while (getline(ss,temp,','))
        {
            tokens.push_back(temp);
        }

        string starts = tokens[0];
        string ends = tokens[1];
        string singName = tokens[2];
        string melody = sharpCheck(tokens[3]);

        singMap[singName] = SingInfo();

        int startTime = getTime(starts);
        int endTime = getTime(ends);

        singMap[singName].startTime = startTime;
        singMap[singName].singTime = endTime - startTime;
        singMap[singName].singFlot = melody;
        singMap[singName].flotCount = melody.size();
        singMap[singName].idx = idx;
        idx++;
    }

    for (auto& si : singMap)
    {
        if (isInMelody(m, si.second))
        {
            if (answer == "(None)")
            {
                answer = si.first;
                continue;
            }

            if (singMap[answer].singTime < si.second.singTime || // 현재 재생 시간이 더 짧음
                (singMap[answer].singTime == si.second.singTime && // 같은데 저쪽이 먼저 들어옴
                    singMap[answer].idx > si.second.idx))
            {
                answer = si.first;
            }
        }
    }

    return answer;
}