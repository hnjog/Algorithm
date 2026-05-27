#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int solution(int balls, int share) {
    if (balls == share)
    {
        return 1;
    }
    ull answer = 1;

    int ind = 1;
    int indLimit = balls - share;
    int rInd = balls;
    int rIndLimit = share;

    while (ind < indLimit || rInd > rIndLimit)
    {
        if (rInd > rIndLimit)
        {
            answer *= rInd;
            rInd--;
        }

        if (ind <= indLimit)
        {
            answer /= ind;
            ind++;
        }
    }

    return (int)answer;
}