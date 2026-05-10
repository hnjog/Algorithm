#include <string>
#include <vector>

using namespace std;

int NearTwo(int as)
{
    int a = 1;
    while(a < as)
    {
        a *= 2;
    }
    return a;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int as = answer.size();
    int t = NearTwo(as) - as;
    for(int i=0;i<t;i++)
        answer.push_back(0);
    
    return answer;
}