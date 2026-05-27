#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    
    int size = numbers.size();
    int n1 = numbers[0] * numbers[1];
    int n2 = numbers[size - 1] * numbers[size - 2];
    
    answer = n1 > n2 ? n1 : n2;
    
    return answer;
}