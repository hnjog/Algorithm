#include <set>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    set<int> s(numbers.begin(), numbers.end());
    
    for(int i = 1; i <= 9;i++)
    {
        if(s.find(i) == s.end())
            answer+=i;
    }
    
    return answer;
}