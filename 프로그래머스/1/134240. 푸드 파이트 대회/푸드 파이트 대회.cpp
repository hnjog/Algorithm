#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int v = 1;
    for(int i=1;i<food.size();i++)
    {
        for(int j = 0; j <food[i] /2;j++)
        {
            answer += to_string(v);
        }
        v++;
    }
    
    answer += "0";
    
    string temp = "";
    for(int i = answer.size() - 2;i >=0;i--)
    {
        temp += answer[i];
    }
    answer += temp;
    return answer;
}