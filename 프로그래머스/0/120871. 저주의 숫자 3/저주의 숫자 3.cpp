#include <string>
#include <vector>

using namespace std;

bool isThree(int n)
{
    if (n % 3 == 0)
        return true;

    int ind = 1;
    while (true)
    {
        int temp = n % (ind * 10) / ind;
        if (temp == 3)
        {
            return true;
        }

        ind *= 10;
        if (ind > n)
        {
            break;
        }
    }

    return false;
}

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        answer++;

        while(isThree(answer))
{
    answer++;
}
    }
    return answer;
}
