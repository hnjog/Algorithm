#include <string>
#include<stack>
#include<queue>
#include<unordered_map>

using namespace std;

unordered_map<char, char> umaps;

// 내부에서 파헤칠 예정이기에 그냥 복사하는 쪽으로
bool checkRight(queue<char> s)
{
    stack<char> st;

    while (s.empty() == false)
    {
        char c = s.front();
        s.pop();

        // 닫는 문자
        if (umaps.find(c) == umaps.end())
        {
            // 텅 비어있는데 닫힌 문자부터 들어오면 당연히 잘못
            if (st.empty())
            {
                return false;
            }

            // 가장 마지막에 들어온 여는 문자
            char c2 = st.top();

            // 잘못된 닫는 문자
            if (umaps[c2] != c)
            {
                return false;
            }

            st.pop();
        }
        else // 여는 문자
        {
            st.push(c);
        }
    }

    // 아직 남아있네...?
    if (st.empty() == false)
        return false;

    return true;
}

int solution(string s) {
    int answer = 0;
    umaps['('] = ')';
    umaps['['] = ']';
    umaps['{'] = '}';

    queue<char> q;

    for (char c : s)
    {
        q.push(c);
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (checkRight(q))
            answer++;

        q.push(q.front());
        q.pop();
    }

    return answer;
}
