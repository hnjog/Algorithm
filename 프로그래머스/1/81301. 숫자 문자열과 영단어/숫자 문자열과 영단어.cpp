#include <string>
#include<unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string t = "";
    size_t sSize = s.size();

    unordered_map<string,string> umap;
    umap["zero"] = "0";
    umap["one"] = "1";
    umap["two"] = "2";
    umap["three"] = "3";
    umap["four"] = "4";
    umap["five"] = "5";
    umap["six"] = "6";
    umap["seven"] = "7";
    umap["eight"] = "8";
    umap["nine"] = "9";

    for (size_t i = 0; i < sSize; i++)
    {
        char c = s[i];
        if (c >= '0' && c <= '9')
        {
            t += c;
        }
        else
        {
            string temp = "";
            size_t idx = 0;
            while (i + idx < sSize)
            {
                char nextC = s[i + idx];
                temp += nextC;
                if (umap.find(temp) != umap.end())
                {
                    t += umap[temp];
                    break;
                }
                idx++;
            }

            i += idx;
        }
    }

    answer = stoi(t);

    return answer;
}