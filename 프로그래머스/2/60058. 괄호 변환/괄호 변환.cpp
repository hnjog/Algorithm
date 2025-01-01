#include <string>
#include <vector>

using namespace std;

string func(string u, string v);

bool checkRightStr(string str)
{
    int leftCount = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == ')')
            leftCount--;
        else
            leftCount++;

        if (leftCount < 0)
            return false;
    }

    return true;
}

string recur(string str)
{
    // 나누기
    int leftCount = 0, rightCount = 0;
    bool isRightFirst = false;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            leftCount++;
        else
        {
            rightCount++;
        }

        if (leftCount == rightCount)
        {
            string u(str.begin(), str.begin() + i + 1);
            string v(str.begin() + i + 1, str.end());

            return func(u, v);
        }
    }

    return str;
}

string func(string u, string v)
{
    if (checkRightStr(u))
    {
        return u + recur(v);
    }

    string temp = "(";
    temp += recur(v);
    temp += ")";

    for (int i = 1; i < u.size() - 1; i++)
    {
        if (u[i] == '(')
            u[i] = ')';
        else
            u[i] = '(';
    }

    if (u.size() >= 2)
    {
        u.pop_back();
        u.erase(0, 1);
    }

    return temp + u;
}


string solution(string p) {
    if (p.size() == 0)
        return "";

    return recur(p);
}
