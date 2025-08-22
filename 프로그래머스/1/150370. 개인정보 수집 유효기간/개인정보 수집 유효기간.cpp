#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    unordered_map<char, ull> term;

    ull todays = stol(today.substr(0, 4)) * (ull)28 * 12;
    todays += stol(today.substr(5, 2)) * (ull)28;
    todays += stol(today.substr(8, 2));

    for (string& str : terms)
    {
        char c = str[0];
        ull days = stol(str.substr(2, 4)) * (ull)28;
        term[c] = days;
    }

    int idx = 1;
    for (string& str : privacies)
    {
        ull start = stol(str.substr(0, 4)) * (ull)28 * 12;
        start += stol(str.substr(5, 2)) * (ull)28;
        start += stol(str.substr(8, 2));

        char t = str[11];

        start += term[t];

        if (todays >= start)
            answer.push_back(idx);

        idx++;
    }

    return answer;
}