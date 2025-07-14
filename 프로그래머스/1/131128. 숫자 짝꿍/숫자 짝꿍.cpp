#include <string>
#include <vector>
#include <map>

using namespace std;

char nc[10] = { '0','1','2','3','4','5','6','7','8','9' };

string solution(string X, string Y) {
    string answer = "";
    map<char, int> xm, ym;
    for (char c : X)
        xm[c]++;

    for (char c : Y)
        ym[c]++;

    for (int i = 9; i >= 0; i--)
    {
        int v = min(xm[nc[i]], ym[nc[i]]);

        for (int j = 0; j < v; j++)
            answer += nc[i];
    }

    if (answer == "")
        answer = "-1";
    else if (answer[0] == '0')
        answer = "0";

    return answer;
}