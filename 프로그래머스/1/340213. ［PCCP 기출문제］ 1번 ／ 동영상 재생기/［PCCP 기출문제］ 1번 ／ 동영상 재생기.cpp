#include <string>
#include <iostream>
#include <vector>

using namespace std;

int getTimeValue(string str)
{
    string ms = "";
    ms += str[0];
    ms += str[1];
    int m = stoi(ms);
    
    string ss = "";
    ss += str[3];
    ss += str[4];
    int s = stoi(ss);
    
    return m * 60 + s;
}

string getTimeStr(int val)
{
    cout << val << '\n';
    int mV = val / 60;
    cout << mV << '\n';
    
    string m = to_string(mV);
    if(mV < 10)
    {
        m = "0" + m;
    }
    
    int sV = val - mV * 60;
    cout << mV << '\n';
    string s = to_string(sV);
    if(sV < 10)
    {
        s = "0" + s;
    }
    
    string ret = m + ":" + s;
    return ret;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int vLen = getTimeValue(video_len);
    int now =  getTimeValue(pos);
    int opS =  getTimeValue(op_start);
    int opE =  getTimeValue(op_end);
    
    if(now >= opS && now < opE)
    {
        now = opE;
    }
    
    for(string com : commands)
    {
        if(com == "next")
        {
            now += 10;
            if(now > vLen)
                now = vLen;
        }
        else if(com == "prev")
        {
            now -= 10;
            if(now < 0)
                now = 0;
        }
        
        if(now >= opS && now < opE)
        {
            now = opE;
        }
    }
    
    answer = getTimeStr(now);
    
    return answer;
}