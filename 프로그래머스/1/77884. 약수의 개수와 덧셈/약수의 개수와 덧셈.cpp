
using namespace std;

bool getOddCount(int num)
{
    if(num == 1)
        return false;
    
    int ret = 2;
    
    for(int i = 2; i <= num /2;i++)
    {
        if(num % i == 0)
            ret++;
    }
    
    if(ret % 2 == 0)
        return true;
    return false;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right;i++)
    {
        if(getOddCount(i))
        {
            answer+= i;
        }
        else
        {
            answer -= i;
        }
    }
    
    return answer;
}