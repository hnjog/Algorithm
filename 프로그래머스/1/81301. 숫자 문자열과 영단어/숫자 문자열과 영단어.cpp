#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, char> umap;
    umap["zero"] = '0';
    umap["one"] =  '1';
    umap["two"] = '2';
    umap["three"] = '3';
    umap["four"] = '4';
    umap["five"] = '5';
    umap["six"] = '6';
    umap["seven"] = '7';
    umap["eight"] = '8';
    umap["nine"] = '9';

    string temp = "";
    string answers = "";

    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            answers += c;
            continue;
        }

        temp += c;
        if (umap.find(temp) != umap.end())
        {
            answers += umap[temp];
            temp = "";
        }
    }

    return stoi(answers);
}