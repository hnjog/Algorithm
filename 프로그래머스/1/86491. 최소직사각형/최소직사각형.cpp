#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int m1 = 0,m2 = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        int t1 = sizes[i][0];
        int t2 = sizes[i][1];
        if(t1 < t2)
        {
            swap(t1,t2);
        }
        
        if(m1 < t1)
            m1 = t1;
        if(m2 < t2)
            m2 = t2;
    }
    
    answer = m1 * m2;
    
    return answer;
}