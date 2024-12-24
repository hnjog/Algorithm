#include <string>
#include <vector>
#include <map>

using namespace std;

int getTimeValue(string str)
{
    int hour = (str[0] - '0') * 10 + (str[1] - '0');
    int minu = (str[3] - '0') * 10 + (str[4] - '0');

    return hour * 60 + minu;
}

const int startTime = getTimeValue("09:00");

string getTimetoValue(int timeValue)
{
    int hour = timeValue / 60;
    int min = timeValue - hour * 60;

    string strHour = to_string(hour);
    if (strHour.size() == 1)
        strHour = "0" + strHour;
    string strMin = to_string(min);
    if (strMin.size() == 1)
        strMin = "0" + strMin;

    string ret = strHour + ":" + strMin;
    return ret;
}

bool isRightTime(int n, int t, int m, map<int, int> times,const vector<int>& bus, int timeValue)
{
    int fullCount = n * m; // 버스에 타는 사람의 총 량

    for (int i = 0; i < n; i++)
    {
        int nowTime = bus[i];
        int nowCount = 0;

        // 나도 탈 수 있는 시간
        if (timeValue <= nowTime &&
            fullCount == 0)
        {
            // 이미 자리 꽉참
            return false;
        }

        for (auto& a : times)
        {
            // 탈 수 있는 시간이다
            if (nowTime >= a.first)
            {
                // 근데 내가 더 빨리 왔다
                if (timeValue < a.first &&
                    nowCount < m)
                {
                    return true;
                }

                if (nowCount + a.second > m)
                {
                    a.second -= (m - nowCount);
                    nowCount = m;
                    break;
                }
                else
                {
                    nowCount += a.second;
                    a.second = 0;
                    if (nowCount == m)
                        break;
                }
            }
            else
            {
                break;
            }
        }

        if (timeValue <= nowTime &&
            nowCount < m)
        {
            return true;
        }

        fullCount -= m;
    }

    return false;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    map<int,int> times;
    vector<int> bus;

    int start = startTime;
    for (int i = 0; i < n; i++)
    {
        bus.push_back(start + t * i);
    }

    for (string str : timetable)
    {
        int timeValue = getTimeValue(str);
        times[timeValue]++;
    }

    int low = 0;
    int high = getTimeValue("23:59");

    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mid == low)
            break;

        // 탈 수 있는 시간 중 가장 늦은값 구하기
        if (isRightTime(n, t, m, times,bus, mid))
        {
            low = mid;
        }
        else // 중간 값이 탈 수 없는 시간이니 아래로 낮춘다
        {
            high = mid;
        }
    }

    answer = getTimetoValue(low);
    return answer;
}
