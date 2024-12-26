#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int aSize = a.size();
    for(int i = 0; i < aSize;i++)
    {
        answer += (a[i] * b[i]);
    }
    return answer;
}