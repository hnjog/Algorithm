using namespace std;
int solution(int n)
{
    int answer = 0;

    int idx = 10;
    while(true)
    {
        int v = (n % idx) / (idx / 10);
        answer += v;
        if(idx > n)
            break;
        idx *= 10;
    }

    return answer;
}