#include <string>
#include <vector>

using namespace std;

struct MergeV
{
    string value;
    vector<struct point*> pv;
};

struct point
{
    string value = "EMPTY";
    MergeV* mergePtr = nullptr;

    const string& GetValue()
    {
        if (mergePtr == nullptr)
            return value;

        return mergePtr->value;
    }

    void SetValue(const string& str)
    {
        if (mergePtr == nullptr)
        {
            value = str;
            return;
        }

        mergePtr->value = str;
    }
};

void Update(vector<vector<point>>& maps, int r, int c, string& str)
{
    maps[r][c].SetValue(str);
}

void Update(vector<vector<point>>& maps, string& str1,string& str2)
{
    for (vector<point>& pv : maps)
    {
        for (point& p : pv)
        {
            if (p.GetValue() == str1)
            {
                p.SetValue(str2);
            }
        }
    }
}

void Merge(vector<vector<point>>& maps, int r1, int c1, int r2, int c2)
{
    bool bm1 = maps[r1][c1].mergePtr != nullptr;
    bool bm2 = maps[r2][c2].mergePtr != nullptr;

    const string& str1 = maps[r1][c1].GetValue();
    const string& str2 = maps[r2][c2].GetValue();

    // 둘 다 merge 상태가 아니라면
    if (bm1 == false &&
        bm2 == false)
    {
        MergeV* merge = new MergeV();
        merge->pv.push_back(&maps[r1][c1]);
        merge->pv.push_back(&maps[r2][c2]);

        maps[r1][c1].mergePtr = merge;
        maps[r2][c2].mergePtr = merge;
        
        if (str1 == "EMPTY")
            merge->value = str2;
        else
            merge->value = str1;

        return;
    }

    if (bm1 == false)
    {
        MergeV* merge = maps[r2][c2].mergePtr;

        merge->pv.push_back(&maps[r1][c1]);

        maps[r1][c1].mergePtr = merge;

        if (str1 == "EMPTY")
            merge->value = str2;
        else
            merge->value = str1;

        return;
    }

    if (bm2 == false)
    {
        MergeV* merge = maps[r1][c1].mergePtr;

        merge->pv.push_back(&maps[r2][c2]);

        maps[r2][c2].mergePtr = merge;

        if (str1 == "EMPTY")
            merge->value = str2;
        else
            merge->value = str1;

        return;
    }

    MergeV* m1 = maps[r1][c1].mergePtr;
    MergeV* m2 = maps[r2][c2].mergePtr;

    if (m1 == m2)
        return;

    if (m1->value == "EMPTY")
        m1->value = m2->value;

    for (point* pptr : m2->pv)
    {
        pptr->mergePtr = m1;
        m1->pv.push_back(pptr);
    }
    m2->pv.clear();

    delete m2;
}

void UnMerge(vector<vector<point>>& maps, int r, int c)
{
    MergeV* merge = maps[r][c].mergePtr;

    if (merge == nullptr)
        return;

    string val = merge->value;

    for (point* pptr : merge->pv)
    {
        if (pptr != nullptr)
        {
            pptr->mergePtr = nullptr;
            pptr->value = "EMPTY";
        }
    }

    maps[r][c].SetValue(val);

    delete merge;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<vector<point>> maps(51,vector<point>(51));

    for (string& command : commands)
    {
        vector<string> vec;
        string temp = "";

        for (char c : command)
        {
            if (c == ' ')
            {
                vec.push_back(temp);
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        vec.push_back(temp);

        if (vec[0] == "UPDATE")
        {
            if (vec.size() == 4)
            {
                int r = stoi(vec[1]);
                int c = stoi(vec[2]);
                Update(maps, r, c, vec[3]);
            }
            else if(vec.size() == 3)
            {
                Update(maps, vec[1], vec[2]);
            }
        }
        else if (vec[0] == "MERGE")
        {
            int r1 = stoi(vec[1]);
            int c1 = stoi(vec[2]);
            int r2 = stoi(vec[3]);
            int c2 = stoi(vec[4]);
            Merge(maps, r1, c1, r2, c2);
        }
        else if (vec[0] == "UNMERGE")
        {
            int r = stoi(vec[1]);
            int c = stoi(vec[2]);
            UnMerge(maps, r, c);
        }
        else
        {
            int r = stoi(vec[1]);
            int c = stoi(vec[2]);
            answer.emplace_back(maps[r][c].GetValue());
        }
    }

    return answer;
}