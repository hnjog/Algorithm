#include <string>
#include <vector>
#include<limits.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int min = INT_MAX;
    int max = INT_MIN;

    bool isMinus = false;
    int temp = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == ' ')
        {
            if (isMinus)
                temp *= -1;

            if (temp < min)
                min = temp;

            if (temp > max)
                max = temp;

            isMinus = false;
            temp = 0;
        }
        else if (c == '-')
        {
            isMinus = true;
        }
        else
        {
            temp *= 10;
            temp += (c - '0');

            if (i == s.size() - 1)
            {
                if (isMinus)
                    temp *= -1;

                if (temp < min)
                    min = temp;

                if (temp > max)
                    max = temp;
            }
        }

    }

    answer = to_string( min) + " " + to_string(max);

    return answer;
}