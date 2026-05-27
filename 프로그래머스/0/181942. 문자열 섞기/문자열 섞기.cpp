#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int index = 0;
    int size = str1.size();
    while(index < size)
    {
        answer += str1[index];
        answer += str2[index];
        index++;
    }
    return answer;
}