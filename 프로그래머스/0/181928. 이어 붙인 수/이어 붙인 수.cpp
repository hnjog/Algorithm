#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int odd =0;
    int even = 0;
    for(int n : num_list)
    {
        if(n % 2 == 0)
        {
            even *= 10;
            even += n;
        }
        else
        {
            odd *= 10;
            odd += n;
        }
    }
    
    return even + odd;
}