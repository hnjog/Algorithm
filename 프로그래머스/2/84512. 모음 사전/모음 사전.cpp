#include <string>
#include <vector>

using namespace std;

const int c_range = 5;
const char c_arr[c_range] = { 'A','E','I','O','U' };

int recur(const string& targetWord, string nowWord, int&& count)
{
    if (targetWord == nowWord)
    {
        return count;
    }

    if (nowWord.size() >= c_range)
    {
        return 0;
    }

    for (int i = 0; i < c_range; i++)
    {
        count++;
        int ret = recur(targetWord, nowWord + c_arr[i], move(count));
        if (ret != 0)
            return ret;
    }

    return 0;
}

int solution(string word) {
    return recur(word, "", 0);
}