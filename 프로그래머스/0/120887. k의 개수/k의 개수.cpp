#include <string>
#include <vector>

using namespace std;

int isCheckK(int n, int k)
{
    int result = 0;
    int ind = 1;

    while (true)
    {
        int temp = (n % (ind * 10)) / ind;

        if (temp == k)
            result++;

        ind *= 10;
        if (ind > n)
        {
            break;
        }
    }

    return result;
}

int solution(int i, int j, int k) {
    int answer = 0;

    for (int a = i; a <= j; a++)
    {
        answer += isCheckK(a, k);
    }

    return answer;
}