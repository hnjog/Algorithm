#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int size = numbers.size();
    
    int index = 0;
    for(int i = 0; i < k - 1; i++)
    {
        index += 2;
        index %= size;
    }
    
    int answer = numbers[index];
    
    return answer;
}