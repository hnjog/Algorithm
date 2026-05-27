#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string polynomial) {
    string answer = "";

    istringstream iss(polynomial);
    vector<string> words;
    string word;

    while (iss >> word)
    {
        words.push_back(word);
    }

    int size = words.size();

    int xValue = 0;
    int value = 0;

    for (int i = 0; i < size; i++)
    {
        if (words[i] == "+")
            continue;

        int tempSize = words[i].size();
        bool isXValue = words[i][tempSize - 1] == 'x';
        int baseValue = 0;

        int fSize = tempSize;
        if (isXValue == true)
        {
            fSize--;
        }

        for (int j = 0; j < fSize; j++)
        {
            baseValue *= 10;
            baseValue += static_cast<int>(words[i][j] - '0');
        }

        if (isXValue == true)
        {
            xValue += baseValue;
            if (baseValue == 0)
                xValue++;
        }
        else
        {
            value += baseValue;
        }
    }

    if (xValue > 0)
    {
        if (xValue > 1)
{
    answer += to_string(xValue);
}

answer = answer + "x";

        if (value > 0)
        {
            answer += " + ";
        }
    }

    if (value > 0)
    {
        answer = answer + to_string(value);
    }

    return answer;
}