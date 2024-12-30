#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dic;
    char a = 'A';
    int idx = 1;
    for (int i = 0; i < 26; i++)
    {
        string temp = "";
        temp += a;
        dic[temp] = idx;
        a++;
        idx++;
    }

    int mSize = msg.size();
    for (int i = 0; i < mSize;i++)
    {
        string temp = "";
        string temp2 = "";
        int j = i;
        bool finalCheck = false;
        
        while (j < mSize)
        {
            temp += msg[j];
            j++;
            if (dic.find(temp) == dic.end())
            {
                answer.push_back(dic[temp2]);
                dic[temp] = idx;
                if (temp2.size() > 1)
                {
                    i += (temp2.size() - 1);
                }
                idx++;
                finalCheck = true;
                break;
            }
            temp2 = temp;
        }

        if (finalCheck == false)
        {
            answer.push_back(dic[temp]);
            if (temp.size() > 1)
            {
                i += (temp.size() - 1);
            }
        }
    }

    return answer;
}
