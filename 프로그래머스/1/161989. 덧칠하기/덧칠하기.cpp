#include <vector>
#include <stack>

using namespace std;

int solution(int n, int m, vector<int> section) {
    stack<int> st;
    for(int s : section)
    {
        st.push(s);
    }
    
    m--;
    
    int answer = 1;
    int enable = st.top() - m;
    st.pop();
    while(st.empty() == false)
    {
        int t = st.top();
        if(t < enable)
        {
            answer++;
            enable = t - m;
        }
        st.pop();
    }
    
    return answer;
}