#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    int answer = price;
    
    int fiveDisccountValue = 100000;
    int tenDisccountValue = 300000;
    int twenDisccountValue = 500000;
    
    if(answer >= twenDisccountValue)
    {
        answer = answer * 0.8;
    }
    else if(answer >= tenDisccountValue)
    {
        answer = answer * 0.9;
    }
    else if(answer >= fiveDisccountValue)
    {
        answer = answer * 0.95;
    }
    
    return answer;
}