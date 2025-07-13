#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> receipt = {1,2,3,1};
    vector<int> stack;
    
    for(int in : ingredient)
    {
        stack.push_back(in);
        if(stack.size() < 4)
        {
            continue;
        }
        
        if(in == 1)
        {
            bool isSuccess = true;
            
            for(int i = 0, idx = stack.size() - 4; i < 4, idx < stack.size();i++,idx++)
            {
                if(receipt[i] != stack[idx])
                {
                    isSuccess = false;
                    break;
                }
            }
            
            if(isSuccess)
            {
                for(int i = 0; i <4;i++)
                    stack.pop_back();
                
                answer++;
            }
        }
    }
    return answer;
}