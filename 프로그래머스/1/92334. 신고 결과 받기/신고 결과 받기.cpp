#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());

    map<string, set<string>> repMap;
    map<string, int> res;

    for (string& str : id_list)
    {
        res[str] = 0;
    }

    for (string str : report)
    {
        int pos = str.find(' ');
        string a = str.substr(0, pos);
        string b = str.substr(pos + 1, str.size());

        repMap[b].insert(a);
    }

    for (auto& it : repMap)
    {
        if (it.second.size() >= k)
        {
            for (const string& str : it.second)
            {
                res[str]++;
            }
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        answer[i] = res[id_list[i]];
    }

    return answer;
}
