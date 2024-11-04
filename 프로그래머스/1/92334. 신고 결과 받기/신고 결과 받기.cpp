#include <string>
#include <vector>
#include<map>
#include<set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    map<string, set<string>> umap;
    map<string, int> idxMap;

    int idx = 0;
    for (string id : id_list)
    {
        umap[id] = set<string>();
        idxMap[id] = idx;
        idx++;
    }

    for (string r : report)
    {
        int pos = r.find(' ');
        string f = r.substr(0, pos);  // 신고 한 녀석
        string s = r.substr(pos + 1); // 신고 받은 녀석

        umap[s].insert(f);
    }

    for (const auto& u : umap)
    {
        if (u.second.size() < k)
            continue;

        for (string reporter : u.second)
        {
            answer[idxMap[reporter]]++;
        }
    }

    return answer;
}