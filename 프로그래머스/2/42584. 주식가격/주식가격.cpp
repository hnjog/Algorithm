#include <stack>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n,0);

    stack<pii> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() ||
            prices[i] >= st.top().first)
        {
            st.push({ prices[i],i });
            continue;
        }
        else
        {
            while (st.empty() == false &&
                prices[i] < st.top().first)
            {
                answer[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.push({ prices[i],i });
        }
    }

    while (st.empty() == false)
    {
        answer[st.top().second] = n - 1 - st.top().second;
        st.pop();
    }

    return answer;
}