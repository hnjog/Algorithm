#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    map<string, map<string, int>> fmap;

    for (string& st : gifts)
    {
        auto a = st.find(' ');

        string lf = st.substr(0,a);
        string rf = st.substr(a + 1);

        fmap[lf][rf]++;
    }

    map<string, int> pc;

    for (auto& m : fmap)
    {
        for (auto& b : m.second)
        {
            pc[m.first] += b.second;
            pc[b.first] -= b.second;
        }
    }

    for (auto& m : fmap)
    {
        string lf = m.first;
        int count = 0;

        for(string& rf : friends)
        {
            if (rf == lf)
                continue;

            if (fmap[lf][rf] < fmap[rf][lf])
                continue;

            if (fmap[lf][rf] == fmap[rf][lf] &&
                pc[lf] <= pc[rf])
                continue;

            count++;
        }

        if (count > answer)
            answer = count;
    }

    return answer;
}