#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

const string base[2] = { "님이 들어왔습니다.","님이 나갔습니다." };

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;	// uid / name
	queue<pair< string,string>> q;		// uid를 기억하여 순서 결정

	for (string str : record)
	{
		istringstream stream(str);
		vector<string> rec;
		string temp;
		while (stream >> temp)
		{
			rec.push_back(temp);
		}

		if (rec[0] == "Enter")
		{
			m[rec[1]] = rec[2];
			q.push({rec[0], rec[1] });
		}
		else if (rec[0] == "Leave")
		{
			q.push({ rec[0],rec[1] });
		}
		else //change
		{
			m[rec[1]] = rec[2];
		}
	}

	// q 순서에 따라 문자열 answer에 넣기
	while (q.empty() == false)
	{
		auto p = q.front();
		q.pop();

		if (p.first == "Enter")
		{
			answer.push_back(m[p.second] + base[0]);
		}
		else
		{
			answer.push_back(m[p.second] + base[1]);
		}
	}

	return answer;
}