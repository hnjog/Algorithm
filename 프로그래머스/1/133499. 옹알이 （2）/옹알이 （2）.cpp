#include <string>
#include <vector>

using namespace std;

const string canStr[4] = { "aya", "ye", "woo", "ma" };

bool isCan(string& str)
{
    int ssize = str.size();
    if (ssize <= 1)
        return false;

    int idx = 0;
    int prev = -1;
    while (idx < ssize)
    {
        char& c = str[idx];
        int t = ssize - idx;

        switch (c)
        {
        case 'a':
        {
            if (prev == 0)
                return false;

            const int targetSize = canStr[0].size();
            if (t < targetSize)
                return false;

            string tempStr(str.begin() + idx, str.begin() + idx + targetSize);

            if (tempStr != canStr[0])
                return false;

            idx += targetSize;
            prev = 0;
        }
        break;
        case 'y':
        {
            if (prev == 1)
                return false;

            const int targetSize = canStr[1].size();
            if (t < targetSize)
                return false;

            string tempStr(str.begin() + idx, str.begin() + idx + targetSize);

            if (tempStr != canStr[1])
                return false;

            idx += targetSize;
            prev = 1;
        }
        break;
        case 'w':
        {
            if (prev == 2)
                return false;

            const int targetSize = canStr[2].size();
            if (t < targetSize)
                return false;

            string tempStr(str.begin() + idx, str.begin() + idx + targetSize);

            if (tempStr != canStr[2])
                return false;

            idx += targetSize;
            prev = 2;
        }
        break;
        case 'm':
        {
            if (prev == 3)
                return false;

            const int targetSize = canStr[3].size();
            if (t < targetSize)
                return false;

            string tempStr(str.begin() + idx, str.begin() + idx + targetSize);

            if (tempStr != canStr[3])
                return false;

            idx += targetSize;
            prev = 3;
        }
        break;
        default:
            return false;
        }
    }

    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (string& str : babbling)
    {
        if (isCan(str))
        {
            answer++;
        }
    }
    return answer;
}