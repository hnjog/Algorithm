#include <string>
#include <vector>

using namespace std;

vector<string> tokenize(string str)
{
    vector<string> ret;
    string temp = "";

    for (char c : str)
    {
        if (c == ' ')
        {
            if(temp.size() > 0)
                ret.push_back(temp);

            temp.clear();
        }
        else
        {
            temp += c;
        }
        
    }
    if (temp.size() > 0)
        ret.push_back(temp);
    
    return ret;
}

int getResult(string b)
{
    vector<string> r = tokenize(b);

    int a = stoi(r[0]);
    int c = stoi(r[2]);

    if (r[1] == "*")
        return a * c;

    if (r[1] == "+")
        return a + c;

    return a - c;
}

int solution(string binomial) {
    return getResult(binomial);
}