#include <string>
#include <vector>
#include<algorithm>
#include<set>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    set<int> s;
    for(int i = 1; i < n / 2; i++)
    {
        if(n % i == 0)
        {
            s.insert(i);
            s.insert(n / i);
        }
    }
    s.insert(n);
    
    for(auto a : s)
    {
        answer.push_back(a);
    }
    
    return answer;
}