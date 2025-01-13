using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int remain = 0;
    
    while (n >= a)
    {
        if (n % a != 0)
        {
            remain = n % a;
            n -= remain;
        }

        int nextN = (n / a) * b;

        answer += nextN;

        n = nextN;
        n += remain;
        remain = 0;
    }
    
    return answer;
}