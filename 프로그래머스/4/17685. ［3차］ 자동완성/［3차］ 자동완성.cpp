#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    struct node
    {
        unordered_map<char, unique_ptr<node>> m;
        int count = 0;

        void insert(const string& str, int ind)
        {
            if (ind >= str.size())
                return;

            if (m.find(str[ind]) == m.end())
            {
                m[str[ind]] = make_unique<node>();
            }

            m[str[ind]]->count += 1;
            m[str[ind]]->insert(str, ind + 1);
        }

        int findCount(const string& str, int ind)
        {
            if (ind >= str.size())
                return ind;

            if (m[str[ind]]->count == 1)
                return ind + 1;

            return m[str[ind]]->findCount(str, ind + 1);
        }
    };

    int answer = 0;
    node start;
    for (const auto& word : words)
    {
        start.insert(word, 0);
    }

    for (const auto& word : words)
    {
        answer += start.findCount(word, 0);
    }

    return answer;
}