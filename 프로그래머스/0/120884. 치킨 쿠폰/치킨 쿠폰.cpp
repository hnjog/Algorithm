#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int coupon = 0;
    int answer = 0;
    
    while(true)
    {
        coupon += chicken;
        chicken = 0;
        if(coupon >= 10)
        {
            int temp = coupon / 10;
            answer += temp;
            chicken += temp;
            coupon -= (temp * 10);
        }
        else
        {
            break;
        }
    }
    
    return answer;
}