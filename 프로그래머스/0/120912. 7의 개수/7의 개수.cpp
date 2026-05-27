#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for (int i = 0; i < array.size(); i++)
    {
        int index = 1;
        while (true)
        {
            int temp = (array[i] % (index * 10)) / index;
            if (temp == 7)
            {
                answer++;
            }

            index *= 10;
            if (index > array[i])
            {
                break;
            }
        }
    }

    return answer;
}