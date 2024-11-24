#include <string>
#include <vector>
#include<math.h>
#include<algorithm>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long n : numbers)
    {
        if (n % 2 == 0)
        {
            answer.push_back(n + 1);
            continue;
        }

        bool isAllOne = true;

        string temp = "";
        long long originN = n;

        while (n >= 1)
        {
            if (n % 2 == 0)
            {
                temp += "0";
                isAllOne = false;
            }
            else
            {
                n--;
                temp += "1";
            }

            n /= 2;
        }

        long long ret = 1;

        if (isAllOne)
        {
            size_t s = temp.size() - 1;
            ret = originN + pow(2, s);
        }
        else
        {
            reverse(temp.begin(), temp.end());
            int idx = 1;
            for(int i = temp.size() - 2; i >= 0; i--)
            {
                if (temp[i] == '0')
                {
                    ret = originN + (pow(2, idx) - pow(2,idx - 1));
                    break;
                }

                idx++;
            }
        }

        answer.push_back(ret);
    }
    return answer;
}