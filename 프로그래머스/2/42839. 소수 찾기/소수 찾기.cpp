#include <string>
#include <vector>
#include<math.h>
#include<memory.h>
#include<set>

using namespace std;

void startRecur(string num, int size, set<int>& s);
void recur(const string& num, string& temp, bool* bArr, int size, set<int>& s);

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
    set<int> s;

    for (int i = 1; i <= size; i++)
    {
        startRecur(numbers, i, s);
    }

    // 여기서 s 돌면서 체크하기
    for (auto a : s)
    {
        if (isPrime(a))
            answer++;
    }


    return answer;
}

// 재귀 시작 용
void startRecur(string num, int size, set<int>& s)
{
    // num의 각 요소들을 시작으로 for문을 돌리고
    // 방문 관련 bool 배열도 이쪽에서 관리한다
    int nSize = num.size();
    bool* bVisit = new bool[nSize];
    memset(bVisit, 0, sizeof(bool) * nSize);
    
    string temp = "";

    for (int i = 0; i < nSize; i++)
    {
        // 여기서 처음 시작하는 부분에 bVisit를 true로 만들어 주고 아래쪽 함수에 넘겨주기
        bVisit[i] = true;
        temp += num[i];
        recur(num,temp, bVisit,size,s);
        bVisit[i] = false;
        temp = "";
    }

    delete[] bVisit;
}

void recur(const string& num,string& temp,bool* bArr,int size, set<int>& s)
{
    // size와 num의 길이가 같으면 break 하면서 return 해야 한다
    // 그리고 나서 check
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
        if (bArr[i] == true)
            continue;

        bArr[i] = true;
        string originTemp = temp;
        temp += num[i];
        recur(num, temp, bArr, size, s);
        temp = originTemp;
        bArr[i] = false;
    }
}