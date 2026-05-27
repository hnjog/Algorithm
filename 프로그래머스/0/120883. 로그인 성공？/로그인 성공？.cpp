#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "fail";
    string id = id_pw[0];
    string pw = id_pw[1];
    
    for(int i = 0; i < db.size();i++)
    {
        if(id == db[i][0])
        {
            if(pw == db[i][1])
            {
                answer = "login";
            }
            else
            {
                answer ="wrong pw";
            }
            break;
        }
    }
    
    return answer;
}