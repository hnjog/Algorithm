#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    int index = 10;
    int tempValue;
    
    do
{
    tempValue = (order % index) / (index / 10);
    if (tempValue != 0 && tempValue % 3 == 0)
    {
        answer++;
    }

    if (index > order)
    {
        break;
    }
    index *= 10;

} while (true);
    
    return answer;
}