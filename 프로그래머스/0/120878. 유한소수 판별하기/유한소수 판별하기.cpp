#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrimeNum(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(int a, int b) {
    int answer = 1;

    int bValue = b;

    vector<int> vb;
    for (int i = 2; i <= a; i++)
    {
        if (isPrimeNum(i) == true && a % i == 0)
        {
            if (bValue % i == 0)
            {
                bValue /= i;
            }
        }
    }

    for (int i = 2; i <= bValue; i++)
    {
        if (isPrimeNum(i) == true && bValue % i == 0)
        {
            if (i != 2 && i != 5)
            {
                answer = 2;
                break;
            }
        }
    }

    return answer;
}