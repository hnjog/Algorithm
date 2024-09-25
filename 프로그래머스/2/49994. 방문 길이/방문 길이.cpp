#include <string>
#include <set>
using namespace std;

typedef pair<int, int> pii;

int solution(string dirs) {
    int answer = 0;
    // y, x
    pii startPos = { 0,0 };
    set<pair<pii,pii>> visitedPos;

    for (char c : dirs)
    {
        pii nextPos = startPos;
        switch (c)
        {
        case 'U':
            nextPos.first++;
            break;
        case 'D':
            nextPos.first--;
            break;
        case 'R':
            nextPos.second++;
            break;
        case 'L':
            nextPos.second--;
            break;
        }

        if (nextPos.first < -5 || nextPos.first > 5 ||
            nextPos.second < -5 || nextPos.second > 5)
            continue;
        

         if (visitedPos.find({ startPos, nextPos }) == visitedPos.end() &&
     visitedPos.find({ nextPos, startPos }) == visitedPos.end())
 {
     answer++;
     visitedPos.insert({ startPos, nextPos });
     visitedPos.insert({ nextPos, startPos });
 }
        startPos = nextPos;
    }

    return answer;
}