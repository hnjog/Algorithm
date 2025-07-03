#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    sort(number.begin(),number.end());
    
    int ns = number.size();
    
    for(int i = 0; i < ns;i++)
    {
        for(int j = i + 1; j < ns;j++)
        {
            for(int k = j + 1; k < ns;k++)
            {
                int v = number[i] + number[j] + number[k];
                
                if(v == 0)
                    answer++;
                else if(v > 0)
                    break;
            }
        }
    }
    
    return answer;
}