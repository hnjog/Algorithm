#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int a : arr)
        answer += a;
    
    answer /= (double)arr.size();
    
    return answer;
}