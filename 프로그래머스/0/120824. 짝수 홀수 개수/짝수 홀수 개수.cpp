#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    int odd = 0;
    int lon = 0;
    
    int listSize = num_list.size();
    
    for(int i = 0; i < listSize;i++)
    {
        if(num_list[i] % 2 == 0)
            odd++;
        else
            lon++;
    }
    
    answer.push_back(odd);
    answer.push_back(lon);
    
    return answer;
}