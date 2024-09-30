#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0;
    int m = 1;
    for(int n : num_list)
    {
        sum += n;
        m *= n;
    }
    
    if(sum * sum > m)
        return 1;
    
    return 0;
}