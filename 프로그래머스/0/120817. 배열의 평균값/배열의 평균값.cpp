#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    int sum = 0;
    int size = numbers.size();
    
    for(auto num : numbers)
    {
        sum += num;
    }
    
    answer = (double)sum / size;
    
    return answer;
}