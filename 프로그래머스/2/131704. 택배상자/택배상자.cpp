#include <vector>
#include<queue>
#include<stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 1;
    // 큐와 스택을 활용하는 문제
    queue<int> baseContainer;
    stack<int> subContainer;

    int firstOrder = order[0];

    int oSize = order.size();

    for (int i = 1; i <= oSize; i++)
    {
        if (firstOrder > i)
        {
            subContainer.push(i);
        }
        else if(firstOrder < i)
        {
            baseContainer.push(i);
        }
    }

    for (int i = 1; i < oSize; i++)
    {
        int nextOrder = order[i];

        bool isFind = false;

        if (baseContainer.empty() == false &&
            baseContainer.front() == nextOrder)
        {
            isFind = true;
            answer++;
            baseContainer.pop();
        }

        if (subContainer.empty() == false &&
            subContainer.top() == nextOrder)
        {
            isFind = true;
            answer++;
            subContainer.pop();
        }

        if (isFind == false)
        {
            if (baseContainer.empty() == false)
            {
                int v = baseContainer.front();
                baseContainer.pop();
                subContainer.push(v);
                i--;
                continue;
            }
            break;
        }
    }

    return answer;
}