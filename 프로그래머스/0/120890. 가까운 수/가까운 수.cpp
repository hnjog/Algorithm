#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    sort(array.begin(),array.end());
    
    int m = 1000;
    int size = array.size();
    for(int i = size - 1; i >= 0;i--)
    {
        if(m >= abs(n - array[i]))
        {
            m = abs(n - array[i]);
            answer = array[i];
        }
    }
    
    return answer;
}