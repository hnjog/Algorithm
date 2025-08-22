#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	int pSize = players.size();
	vector<string> answer = players;

	unordered_map<string, int> raceMap;

	for (int i = 0; i < pSize; i++)
	{
		raceMap[players[i]] = i;
	}

	for (string& str : callings)
	{
		int now = raceMap[str];
		int targetRace = now - 1;


		string& temp = answer[targetRace];

		answer[now] = temp;
		raceMap[str] = targetRace;
		raceMap[temp] = now;
		answer[targetRace] = str;
	}

	return answer;
}