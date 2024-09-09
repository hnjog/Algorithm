#include <string>
#include <vector>
#include<unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    unordered_set<string> usedWord;
    char lastWord = ' ';

    int wSize = words.size();

    for (int i = 0; i < wSize;i++)
    {
        if ((words[i][0] != lastWord && lastWord != ' ') // 단어가 틀린 경우
            || usedWord.find(words[i]) != usedWord.end()) // 이미 사용된 단어인 경우
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }

        usedWord.insert(words[i]);
        lastWord = words[i][words[i].size() - 1];
    }

    return answer;
}