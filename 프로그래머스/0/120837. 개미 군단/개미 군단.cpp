#include <string>
#include <vector>

using namespace std;

const int c_ArrAntPower[3] = { 5,3,1 };

int solution(int hp) {
    int answer = 0;

    int index = 0;
    while (hp != 0)
    {
        int antPower = c_ArrAntPower[index];
        answer += hp / antPower;
        hp %= antPower;
        index++;
    }

    return answer;
}