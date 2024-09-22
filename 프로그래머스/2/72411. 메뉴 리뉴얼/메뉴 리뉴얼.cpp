#include <string>
#include <vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void recur(unordered_map<string, int>& sMap, string temp, const string& str, int index)
{
	if (index >= str.size())
	{
		return;
	}

	temp += str[index];
	sMap[temp]++;

	recur(sMap, temp, str, index + 1);

	temp.pop_back();

	recur(sMap, temp, str, index + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	unordered_map<string, int> sMap;
	int countsArr[11] = { 0, };

	for (string str : orders)
	{
		sort(str.begin(), str.end());

		recur(sMap, "", str, 0);
	}

	for (const auto& it : sMap)
	{
		size_t s = it.first.size();

		if (countsArr[s] < it.second)
		{
			countsArr[s] = it.second;
		}
	}

	for (int length : course)
	{
		int maxLength = countsArr[length];
		if (maxLength < 2)
			continue;

		for (auto it : sMap)
		{
			if (it.first.size() != length)
				continue;

			if (it.second != maxLength)
				continue;

			answer.push_back(it.first);
		}
	}
	
	sort(answer.begin(), answer.end());

	return answer;
}