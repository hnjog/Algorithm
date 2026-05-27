#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool Recur(map<string, map<string, int>>& maps, string& now, vector<string>& route,int n)
{
	route.push_back(now);

	if (route.size() == n)
	{
		return true;
	}

	for (auto& p : maps[now])
	{
		if (p.second > 0)
		{
			p.second--;
			string next = p.first;
			if (Recur(maps, next, route, n))
				return true;
			p.second++;
		}
	}

	route.pop_back();

	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	map<string, map<string,int>> maps;

	for (auto& ticket : tickets)
	{
		string& start = ticket[0];
		string& to = ticket[1];

		maps[start][to]++;
	}

	string start = "ICN";
	Recur(maps, start, answer,tickets.size() + 1);

	return answer;
}