#include <string>
#include <vector>

using namespace std;

string n_jinsu(int n, int num) 
{
    string al[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

    if (num < n) 
    {
        return al[num];
    }
    else 
    {
        return n_jinsu(n, num / n) + al[num % n];
    }
}

string solution(int n, int t, int m, int p) 
{
    string answer = "";
    string numbers = "";

    for (int num = 0; num < t * m; num++) 
    {
        numbers += n_jinsu(n, num);
    }

    int ord = p - 1;
    int nl = numbers.length();
    for (int i = 0; i < nl; i++) 
    {
        if (i % m == ord) 
        {
            answer += numbers[i];
        }

        if (answer.length() == t) 
        {
            break;
        }
    }

    return answer;
}