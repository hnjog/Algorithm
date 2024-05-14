#include <string>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;

void searchRecur(const string& start, map<string, multimap<string, bool>>& maps, int nowCount, int count, vector<vector<string>>& loads, vector<string>& load)
{
	if (nowCount == count)
	{
		loads.push_back(load);
		return;
	}

	if (maps.find(start) == maps.end())
		return;

	for (auto& next : maps[start])
	{
		// 중복 체크는 필요하다
		if (next.second == true)
			continue;

		next.second = true;
		load.push_back(next.first);
		searchRecur(next.first, maps, nowCount + 1, count, loads, load);
		load.pop_back();
		next.second = false;
	}

}

vector<string> solution(vector<vector<string>> tickets) {
	//map<string, map<string, bool>> maps;
	map<string, multimap<string, bool>> maps;

	for (const auto& ticket : tickets)
	{
		if (maps.find(ticket[0]) == maps.end())
		{
			maps[ticket[0]] = multimap<string, bool>();
		}

		maps[ticket[0]].insert(make_pair(ticket[1], false));
	}

	vector<vector<string>> loads;
	vector<string> load;
	load.push_back("ICN");

	searchRecur("ICN", maps, 0, tickets.size(), loads, load);

	sort(loads.begin(), loads.end(), [](const vector<string>& a, const vector<string>& b) {
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
				continue;

			return a[i] < b[i];
		}

		return a.front() < b.front();
		});

	return loads[0];
}