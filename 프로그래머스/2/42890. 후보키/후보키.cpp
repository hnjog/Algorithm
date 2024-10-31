#include <string>
#include <vector>
#include<set>
#include<map>

using namespace std;

bool hasAllElements(const set<int>& setA, const set<int>& setB) 
{
    for (const int& elem : setA) 
    {
        if (setB.count(elem) == 0) 
        {
            return false;
        }
    }
    return true;
}

void dfs(set<int>& uSet,int nowIdx, set<set<int>>& candiKeys,int count,const vector<vector<string>>& relation)
{
    int rSize = relation.size();
    int vSize = relation[0].size();

    uSet.insert(nowIdx);
    if (candiKeys.find(uSet) != candiKeys.end() ||
        uSet.size() > count)
    {
        uSet.erase(nowIdx);
        return;
    }

    if (uSet.size() == count)
    {
        bool isCheck = true;
        set<string> ss;

        for (int i = 0; i < rSize; i++)
        {
            string temp = "";
            for (int uV : uSet)
            {
                temp += relation[i][uV];
            }

            if (ss.find(temp) != ss.end())
            {
                isCheck = false;
                break;
            }

            ss.insert(temp);
        }

        if (isCheck)
        {
            bool isInCheck = false;
            for (const set<int>& candi : candiKeys)
            {
                if (hasAllElements(candi, uSet) ||
                    hasAllElements(uSet, candi))
                {
                    isInCheck = true;
                    break;
                }
            }

            if(isInCheck == false)
                candiKeys.insert(uSet);
        }

    }

    for (int i = nowIdx + 1; i < vSize; i++)
    {
        dfs(uSet, i, candiKeys, count, relation);
    }

    uSet.erase(nowIdx);
}

int solution(vector<vector<string>> relation) {
    int rSize = relation.size();
    int vSize = relation[0].size();

    set<set<int>> candiKeys;

    int count = 1;
    while (count <= vSize)
    {
        for (int i = 0; i < vSize; i++)
        {
            set<int> uSet;
            dfs(uSet,  i, candiKeys, count,relation);
        }

        count++;
    }
    
    return candiKeys.size();
}