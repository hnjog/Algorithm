#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    long long idx = 10;
    while(true)
    {
        int v = (n % idx) / (idx / 10);
        answer.push_back(v);
        if(idx > n)
            break;
        idx *= 10;
    }
    return answer;
}