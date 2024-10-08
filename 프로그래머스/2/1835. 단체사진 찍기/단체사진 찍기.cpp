#include <string>
#include <vector>
#include<unordered_map>
#include<math.h>

using namespace std;

const int MaxCount = 8;
const char peoples[MaxCount] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

struct condition
{
	char Target;
	int distance;
	bool isSame;
	bool isLess;
	bool isMore;
};

void dfs(unordered_map<char, int>& arr, unordered_map<char, vector<condition>>& conditions, int& answer, int nowCount)
{
	if (nowCount == MaxCount)
	{
		answer++;
		return;
	}

	for (char c : peoples)
	{
		// 이미 존재하는 단어
		if (arr.find(c) != arr.end())
			continue;

		// 별다른 조건 없는 수이다
		if (conditions.find(c) == conditions.end())
		{
			arr[c] = nowCount;
			dfs(arr, conditions, answer, nowCount + 1);
			arr.erase(c);
			continue;
		}

		// 나 자신의 조건 검사
		bool isNotCondition = true;
		for (auto& con : conditions[c])
		{
			char target = con.Target;

			// 지금 목표가 배열 내에 없네? 다른 조건 검사
			if (arr.find(target) == arr.end())
			{
				continue;
			}

			// 거리 검사
			int dis = abs(arr[target] - nowCount) - 1;

			if ((con.isLess && dis >= con.distance) ||
				(con.isMore && dis <= con.distance) ||
				(con.isSame && dis != con.distance))
			{
				isNotCondition = false;
				break;
			}
		}

		if (isNotCondition)
		{
			arr[c] = nowCount;
			dfs(arr, conditions, answer, nowCount + 1);
			arr.erase(c);
		}
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;

	unordered_map<char, vector<condition>> conditions;

	for (string str : data)
	{
		char start = str[0];
		char target = str[2];
		char cond = str[3];
		int dis = int(str[4] - '0');

		if (conditions.find(start) == conditions.end())
			conditions[start] = vector<condition>();

		conditions[start].push_back({ target,dis,false,false,false });

		if (conditions.find(target) == conditions.end())
			conditions[target] = vector<condition>();

		conditions[target].push_back({ start,dis,false,false,false });

		switch (cond)
		{
		case '=':
		{
			conditions[start].back().isSame = true;
			conditions[target].back().isSame = true;
		}
		break;
		case '<':
		{
			conditions[start].back().isLess = true;
			conditions[target].back().isLess = true;
		}
		break;
		case '>':
		{
			conditions[start].back().isMore = true;
			conditions[target].back().isMore = true;
		}
		break;
		}
	}

	unordered_map<char, int> arrays; // 일렬로 세운 (사람, 위치)
	dfs(arrays, conditions, answer, 0);

	return answer;
}