#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int nSize = nums.size();
    int selects = nSize / 2;
    unordered_map<int,int> m;
    
    for(int i = 0; i < nSize; i++)
    {
        if(m.find(nums[i]) != m.end())
        {
            m[nums[i]] += 1;
        }
        else
        {
            m[nums[i]] = 1;
        }
    }
    
    int mSize = m.size();
    answer = selects <= mSize ? selects : mSize;
    
    return answer;
}