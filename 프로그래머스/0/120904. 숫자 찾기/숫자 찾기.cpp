#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    vector<int> v;
    
    int index = 1;
    while(true)
    {
        int temp = num % (index * 10) / index;
        v.push_back(temp);
        
        index *= 10;
        if(index > num)
        {
            break;
        }
    }
    
    int size = v.size();
    
   reverse(v.begin(),v.end());
    
    for(int i = 0; i < size;i++)
    {
        if(v[i] == k)
        {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}