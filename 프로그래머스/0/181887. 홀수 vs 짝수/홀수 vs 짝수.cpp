#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> num_list) {
    int oSum = 0;
    int eSum = 0;
    
    bool isOddTime = true; 
    
    for(int n : num_list)
    {
        if(isOddTime)
        {
            oSum += n;
        }
        else
        {
            eSum += n;
        }
        
        isOddTime = !isOddTime;
    }
        
    return max(oSum,eSum);
}