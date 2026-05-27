#include <string>
#include <vector>

using namespace std;

string pushString(string A)
{
    string result = A;

    int size = result.size();
    char temp = result[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        result[i + 1] = result[i];
    }

    result[0] = temp;

    return result;
}

int solution(string A, string B) {
    int answer = 0;

    int size = A.size();

    string temp = A;
    for (int i = 0; i < size; i++)
    {
        if (temp == B)
        {
            return answer;
        }

        answer++;
        temp = pushString(temp);
    }

    return -1;
}