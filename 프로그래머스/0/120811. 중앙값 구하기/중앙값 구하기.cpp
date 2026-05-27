#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    sort(array.begin(),array.end());
    
    int index = array.size() / 2;
    int answer = array[index];
    
    return answer;
}