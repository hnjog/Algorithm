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

void dfs(set<int>& uSet,int startIdx,int nowIdx, map<int, map<string, set<int>>>& overlapV, set<set<int>>& candiKeys,int count,const vector<vector<string>>& relation)
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
        dfs(uSet, startIdx, i, overlapV, candiKeys, count, relation);
    }

    uSet.erase(nowIdx);
}

int solution(vector<vector<string>> relation) {
    int rSize = relation.size();
    int vSize = relation[0].size();

    set<set<int>> candiKeys;

    map<int, map<string,set<int>>> overlapV;
    
    for (int i = 0; i < vSize; i++)
    {
        map<string,int> checkMap;
        bool isOnly = true;
        for (int j = 0; j < rSize; j++)
        {
            if (checkMap.find(relation[j][i]) != checkMap.end())
            {
                isOnly = false;
                
                if (overlapV.find(i) == overlapV.end())
                {
                    overlapV[i] = map<string, set<int>>();
                    overlapV[i][relation[j][i]] = set<int>();
                }

                overlapV[i][relation[j][i]].insert(j);
                overlapV[i][relation[j][i]].insert(checkMap[relation[j][i]]);
            }
            checkMap.insert({ relation[j][i] ,j});
        }

        if (isOnly)
        {
            set<int> uSet;
            uSet.insert(i);
            candiKeys.insert(uSet);
        }
    }

    int count = 2;
    while (count <= vSize)
    {
        for (int i = 0; i < vSize; i++)
        {
            set<int> uSet;
            dfs(uSet, i, i, overlapV, candiKeys, count,relation);
        }

        count++;
    }
    
    return candiKeys.size();
}