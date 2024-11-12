#include <string>
#include<math.h>
#include<algorithm>

using namespace std;

bool isPrime(long long n)
{
    if (n <= 1)
        return false;

    long long sValue = sqrt(n);

    for (long long i = 2; i <= sValue; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int stringCountPrime(string& str)
{
    int ret = 0;

    int sSize = str.size();

    string temp = "";

    for (int i = 0; i < sSize; i++)
    {
        if (str[i] == '0')
        {
            if (temp != "")
            {
                long long v = stoll(temp);
                if(isPrime(v))
                    ret++;
            }

            temp = "";
        }
        else
        {
            temp += str[i];
        }
    }

    if (temp != "")
    {
        long long v = stoll(temp);
        if (isPrime(v))
            ret++;
    }

    return ret;
}

int solution(int n, int k) {
    string sys = "";
    int temp = 0;

    while (n >= k)
    {
        temp = n % k;
        n /= k;

        sys += to_string(temp);
    }
    sys += to_string(n);
    reverse(sys.begin(), sys.end());

    return stringCountPrime(sys);
}