#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (char digit : number) 
    {
        while (answer.empty() == false &&
            answer.back() < digit &&
            k > 0) 
        {
            answer.pop_back();
            k--;
        }
        
        answer.push_back(digit);
    }

    answer.erase(answer.size() - k, k);

    return answer;
}