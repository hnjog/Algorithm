#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    stringstream ss(my_string);
    string temp;
    
    while(ss >> temp)
    {
        answer.push_back(temp);
    }
    
    return answer;
}