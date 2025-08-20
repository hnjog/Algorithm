#include <string>
#include <vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void Recur(unordered_map<string, int>& allMenus,string& nowMenu, string temp, int idx)
{
	if (idx >= nowMenu.size())
		return;

	temp += nowMenu[idx];
	allMenus[temp]++;
	Recur(allMenus, nowMenu, temp, idx + 1);

	temp.pop_back();
	Recur(allMenus, nowMenu, temp, idx + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	int maxOrder[11] = { 0 };
	unordered_map<string, int> allMenus;

	for (string order : orders)
	{
		sort(order.begin(), order.end());
		Recur(allMenus, order, "", 0);
	}

	for (auto it : allMenus)
	{
		int menuSize = it.first.size();
		int orderCount = it.second;

		if (maxOrder[menuSize] < orderCount)
			maxOrder[menuSize] = orderCount;
	}

	for (int length : course)
	{
		if (maxOrder[length] < 2)
			continue;

		for (auto it : allMenus)
		{
			int menuSize = it.first.size();
			int orderCount = it.second;

			if (length != menuSize)
				continue;

			if (maxOrder[menuSize] != orderCount)
				continue;

			answer.push_back(it.first);
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}