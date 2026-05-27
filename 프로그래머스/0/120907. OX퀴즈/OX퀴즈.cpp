#include <string>
#include <vector>
#include<sstream>

using namespace std;

int sToI(string num)
{
    int result = 0;
    int startIndex = 0;
    bool isMinus = false;
    if(num[0] == '-')
    {
        startIndex = 1;
        isMinus = true;
    }
    
    for(int i = startIndex; i < num.size();i++)
    {
        result *= 10;
        result += (int)(num[i] - '0');
    }
    
    if(isMinus)
    {
        result *= -1;
    }
    
    return result;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for(int i = 0; i <quiz.size();i++)
    {
        istringstream iss(quiz[i]);
        vector<string> words;
        string word;
        
        while(iss >> word)
        {
            words.push_back(word);
        }
        
        int wordsSize = words.size();
        
        int sum = sToI(words[0]);
        
        int result = sToI(words[wordsSize - 1]);
        bool bIsOperMinus = false;
        bool bIsOperPlus = false;
for (int j = 1; j < wordsSize - 2; j++)
{
    if (words[j].size() == 1 && words[j][0] == '-')
    {
        bIsOperMinus = true;
        bIsOperPlus = false;
        continue;
    }
    else if (words[j].size() == 1 && words[j][0] == '+')
    {
        bIsOperMinus = false;
        bIsOperPlus = true;
        continue;
    }

    int temp = sToI(words[j]);

    if (bIsOperMinus == true)
    {
        sum -= temp;
    }
    else if(bIsOperPlus == true)
    {
        sum += temp;
    }
}
        
        if(sum != result)
        {
            answer.push_back("X");
        }
        else
        {
            answer.push_back("O");
        }
    }
    
    return answer;
}