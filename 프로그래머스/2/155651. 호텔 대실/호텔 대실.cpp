#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getTimeValue(string& time)
{
    int hourV = ((time[0] - '0') * 10 + (time[1]- '0')) * 60;
    int minV = ((time[3]- '0') * 10 + (time[4]- '0'));
    
    return hourV + minV;
}

bool canUse(string& bookTime, string& roomTime)
{
    if(getTimeValue(bookTime) >= getTimeValue(roomTime) + 10)
        return true;
    
    return false;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
	sort(book_time.begin(), book_time.end(),
		[](auto& a, auto& b)
		{
			return getTimeValue(a[0]) < getTimeValue(b[0]);
		}
	);
    vector<string> rooms;
    
    for(auto& book : book_time)
    {
        bool bNeedNewRoom = true;
        for(string& st : rooms)
        {
            if(canUse(book[0],st))
            {
                bNeedNewRoom = false;
                st = book[1];
                break;
            }
        }
        
        if(bNeedNewRoom)
        {
            answer++;
            rooms.push_back(book[1]);
        }
    }
    
    return answer;
}