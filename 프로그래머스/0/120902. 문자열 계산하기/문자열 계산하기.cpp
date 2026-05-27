#include <string>
#include <vector>
#include <sstream>

using namespace std;

int sToI(string val)
{
    int r = 0;
    
    for(int i = 0; i < val.size();i++)
    {
        r *= 10;
        r += (int)(val[i] - '0');
    }
    
    return r;
}

int solution(string my_string) {
    int answer = 0;
    istringstream is(my_string);
    vector<string> words;
    string word;
    
    while(is >> word)
    {
        words.push_back(word);
    }
    
    answer += sToI(words[0]);
    int temp = 0;
    
    bool isPlus = false;
    bool isMinus = false;
    for(int i = 1; i < words.size();i++)
    {
        if(words[i][0] == '+')
        {
            isPlus = true;
            isMinus = false;
        }
        else if(words[i][0] == '-')
        {
            isPlus = false;
            isMinus = true;
        }
        else
        {
            temp = sToI(words[i]);
            if(isPlus == true)
            {
                answer += temp;
            }
            else if(isMinus == true)
            {
                answer -= temp;
            }
            
        }
    }
    
    return answer;
}