#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include<map>
#include<string.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	const char* delim = ": ";
	struct timeInfo
	{
		int hour;
		int min;
		int fullMin;
		bool isIn;
	};

	map < string, timeInfo> m;
	for (auto& s : records)
	{
		int hour = -1;
		int min = -1;
		string key = "";
		bool isIn = false;
		bool isCheck[3] = { false, };

		char* p_s = strtok((char*)s.c_str(), delim);
		while (p_s != NULL)
		{
			if (hour == -1)
			{
				hour = stoi(p_s);
			}
			else if (min == -1)
			{
				min = stoi(p_s);
			}
			else if (key == "")
			{
				key = string(p_s);
			}
			else if (isIn == false)
			{
				if (strcmp(p_s, "IN") == 0)
				{
					isIn = true;
				}
			}

			p_s = strtok(NULL, delim);
		}

		timeInfo t = { hour,min,0,isIn };
		if (m.find(key) == m.end())
			m[key] = t;
		else
		{
			if (t.isIn == false)
			{
				int vH = t.hour - m[key].hour;
				int vM = t.min - m[key].min;
				int fV = vH * 60 + vM;
				m[key].fullMin += fV;
				m[key].hour = t.hour;
				m[key].min = t.min;
				m[key].isIn = false;
			}
			else
			{
				m[key].hour = t.hour;
				m[key].min = t.min;
				m[key].isIn = true;
			}
		}

	}

	for (auto& a : m)
	{
		if (a.second.isIn == true)
		{
			int vH = 23 - a.second.hour;
			int vM = 59  -a.second.min;
			int fV = vH * 60 + vM;
			a.second.fullMin += fV;
			a.second.isIn = false;
		}

		int r = fees[1]; // 기본시간
		
		int remainMin = a.second.fullMin;

		if (remainMin <= fees[0])
		{
			answer.push_back(r);
			continue;
		}

		remainMin -= fees[0];
		int originRemain = remainMin;
		remainMin /= fees[2];
		if(originRemain % fees[2] != 0)
			remainMin++;

		r += remainMin * fees[3];

		answer.push_back(r);
	}

	return answer;
}
