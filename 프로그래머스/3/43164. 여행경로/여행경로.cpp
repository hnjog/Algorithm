#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, string> pss;

bool dfs(int tSize, unordered_map<string, vector<string>>& um, map<pss,int>& pm, map<pss, int>& visit, const string& start, vector<string>& answer)
{
	answer.push_back(start);

	if (tSize + 1 == answer.size())
	{
		return true;
	}

	for (string& str : um[start])
	{
		if (pm.find({ start,str }) == pm.end())
			continue;

		if (visit[{start, str}] >= pm[{start, str}])
			continue;

		visit[{start, str}]++;

		if (dfs(tSize, um, pm,visit, str, answer) == true)
			return true;

		visit[{start, str}]--;
	}
	
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	unordered_map<string, vector<string>> um;
	map<pss, int> pm,visit;

	for (const auto& ticket : tickets)
	{
		const string& start = ticket[0];
		const string& target = ticket[1];

		um[start].push_back(target);
		pm[{start, target}]++;
	}

	for (auto& targets : um)
	{
		sort(targets.second.begin(), targets.second.end(), [](const string& a, const string& b) { return a < b; });
	}
	
	dfs(tickets.size(), um, pm, visit, "ICN", answer);
	return answer;
}