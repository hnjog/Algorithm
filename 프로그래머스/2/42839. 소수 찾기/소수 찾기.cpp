#include <string>
#include <vector>
#include<math.h>
#include<memory.h>
#include<set>

using namespace std;

void recur(const string& num,string& temp,vector<bool>& bVisit,int size, set<int>& s)
{
    if (temp.size() == size)
    {
        int r = stoi(temp);
        s.insert(r);
        return;
    }
    
    int nSize = num.size();

    for (int i = 0; i < nSize; i++)
    {
        // 이미 탐색이 완료된 부분
        if (bVisit[i] == true)
            continue;

        bVisit[i] = true;
        temp.push_back(num[i]);
        recur(num,temp, bVisit,size,s);
        temp.pop_back();
        bVisit[i] = false;
    }
}

bool isPrime(int n)
{
    if (n < 2)
        return false;

    if (n < 4)
        return true;

    int sqn = sqrt(n);

    for (int i = 2; i <= sqn + 1; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;

    int size = numbers.size();
    vector<bool> bVisit(size,false);
    set<int> s;
    string temp = "";

    for (int i = 1; i <= size; i++)
    {
        recur(numbers,temp, bVisit,i,s);
    }

    // 여기서 s 돌면서 체크하기
    for (auto a : s)
    {
        if (isPrime(a))
            answer++;
    }

    return answer;
}

