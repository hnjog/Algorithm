#include <string>
#include<map> 
#include<math.h>

using namespace std;

int solution(string str1, string str2) {

    map<string,int> str1Map, str2Map;

    string temp = "";

    for (int i = 0; i < str1.size(); i++)
    {
        char c = str1[i];
        if ('a' <= c && c <= 'z')
        {
            c = c - ('a' - 'A');
            temp += c;
        }
        else if ('A' <= c && c <= 'Z')
        {
            temp += c;
        }
        else
        {
            temp = "";
            continue;
        }

        if (temp.size() == 2)
        {
            str1Map[temp]++;
            char t = temp[1];
            temp = t;
        }
    }

    temp = "";
    for (int i = 0; i < str2.size(); i++)
    {
        char c = str2[i];
        if ('a' <= c && c <= 'z')
        {
            c = c - ('a' - 'A');
            temp += c;
        }
        else if ('A' <= c && c <= 'Z')
        {
            temp += c;
        }
        else
        {
            temp = "";
            continue;
        }

        if (temp.size() == 2)
        {
            str2Map[temp]++;
            char t = temp[1];
            temp = t;
        }
    }

    if (str1Map.size() == 0 &&
        str2Map.size() == 0)
    {
        return 65536;
    }

    map<string,int> minMap, maxMap;

    for (const auto& s : str1Map)
    {
        if (str2Map.find(s.first) != str2Map.end())
        {
            minMap[s.first] = min(str1Map[s.first], str2Map[s.first]);
            maxMap[s.first] = max(str1Map[s.first], str2Map[s.first]);
        }
        else
        {
            maxMap[s.first] = str1Map[s.first];
        }
    }

    for (auto s : str2Map)
    {
        if (str1Map.find(s.first) != str1Map.end())
        {
            minMap[s.first] = min(str1Map[s.first], str2Map[s.first]);
            maxMap[s.first] = max(str1Map[s.first], str2Map[s.first]);
        }
        else
        {
            maxMap[s.first] = str2Map[s.first];
        }
    }

    int minV = 0;
    int maxV = 0;

    for (const auto& v : minMap)
    {
        minV += v.second;
    }

    for (const auto& v : maxMap)
    {
        maxV += v.second;
    }

    int answer = (int)((float)(minV / (float) maxV) * 65536);

    return answer;
}