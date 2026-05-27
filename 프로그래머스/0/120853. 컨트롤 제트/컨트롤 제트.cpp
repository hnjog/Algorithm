#include <string>
#include <vector>
#include<sstream>
#include<math.h>

using namespace std;

int solution(string s) {
    int answer = 0;

    istringstream iss(s);
    vector<string> words;
    string word;

    while (iss >> word)
    {
        words.push_back(word);
    }

    int before = 0;
    int sum = 0;
    for (int i = 0; i < words.size(); i++)
    {
        int wordSize = words[i].size();
        int temp = 0;
        bool isMinus = false;
        for (int j = 0; j <wordSize;j++)
        {
            if (isdigit(words[i][j]) == false)
            {
                if (words[i][j] == 'Z')
                {
                    sum -= before;
                    break;
                }
                else
                {
                    isMinus = true;
                    continue;
                }
            }
            
            temp += (words[i][j] - '0') * (int)(pow(10,wordSize - 1 - j));
        }

        if (isMinus == false)
        {
            sum += temp;
            before = temp;
        }
        else
        {
            sum -= temp;
            before = -temp;
        }
    }

    answer = sum;

    return answer;
}