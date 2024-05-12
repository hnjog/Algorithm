#include <string>
#include <vector>

using namespace std;

const int c_range = 5;
const char c_arr[c_range] = { 'A','E','I','O','U' };
bool isFind = false;

void recur(const string& targetWord, string nowWord, int& count);

int solution(string word) {
    int answer = 0;
    recur(word, "", answer);

    int b = 10;

    return answer;
}

void recur(const string& targetWord, string nowWord, int& count)
{
    if (targetWord == nowWord)
    {
        isFind = true;
        return;
    }

    if (nowWord.size() >= c_range)
    {
        return;
    }

    for (int i = 0; i < c_range; i++)
    {
        if (isFind)
        {
            break;
        }

        string temp = nowWord;
        nowWord += c_arr[i];
        count++;
        recur(targetWord, nowWord, count);
        nowWord = temp;
    }
}