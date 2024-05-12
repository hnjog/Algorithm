#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    int pSize = phone_book.size();
    
    sort(phone_book.begin(),phone_book.end());
    
    for(int i = 0; i < pSize - 1; i++)
    {
        if(phone_book[i + 1].find(phone_book[i]) == 0)
        {
            return false;
        }
    }
    
    return answer;
}