#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<pair<int,int>> st;
    for(int i = 0; i <numbers.size();i++)
    {
        while(st.empty() == false &&
             st.top().second < numbers[i])
        {
            answer[st.top().first] = numbers[i];
            st.pop();
        }
        
        st.push({i,numbers[i]});
    }
    
    while(st.empty() == false)
    {
        answer[st.top().first] = -1;
        st.pop();
    }
    
    return answer;
}