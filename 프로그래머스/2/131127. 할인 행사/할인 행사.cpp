#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

bool isSameMap(unordered_map<string, int>& wMap, unordered_map<string, int>& tMap, const vector<string>& want)
{
	int wSize = want.size();

	for (int i = 0; i < wSize; i++)
	{
		if (tMap[want[i]] != wMap[want[i]])
		{
			return false;
		}
	}

	return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	int wSize = want.size();

	unordered_map<string, int> wantMap;
	for (int i = 0; i < wSize; i++)
	{
		wantMap[want[i]] = number[i];
	}

	int dSize = discount.size();
	unordered_map<string, int> tempMap;

	for (int i = 0; i < 10; i++)
	{
		tempMap[discount[i]]++;
	}

	if (isSameMap(tempMap, wantMap, want))
		answer++;

	for (int i = 10; i < dSize; i++)
	{
		tempMap[discount[i]]++;
		tempMap[discount[i - 10]]--;

		if (isSameMap(tempMap, wantMap, want))
			answer++;
	}

	return answer;
}