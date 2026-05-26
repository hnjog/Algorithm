#include <string>
#include <vector>

using namespace std;

char als[5] = { 'A', 'E', 'I', 'O', 'U' };

bool FindStr(const string& word, string& now, int& answer)
{
    if (now == word)
    {
        return true;
    }

    if (now.size() > 5)
        return false;

    answer++;

    for (char c : als)
    {
        now.push_back(c);

        if (FindStr(word, now, answer) == true)
            return true;

        now.pop_back();
    }

    return false;
}

int solution(string word) {
    int answer = 0;
    string now = "";
    FindStr(word, now, answer);
    return answer;
}