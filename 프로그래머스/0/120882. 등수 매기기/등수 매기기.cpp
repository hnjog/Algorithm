#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
	vector<int> answer;
	vector<pair<int, int>> vec;
	vec.reserve(score.size());

	for (int i = 0; i < score.size(); i++)
	{
		vec.push_back(make_pair(score[i][0] + score[i][1], i));
		answer.push_back(0);
	}

	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b)->bool { return a.first > b.first; });

	int rank = 0;
	int temp = 0;
	int dis = 1;

	for (int i = 0; i < vec.size(); i++)
	{
		if (temp != vec[i].first)
		{
			rank+= dis;
			temp = vec[i].first;
			dis = 1;
		}
		else
		{
			dis++;
		}

		answer[vec[i].second] = rank;
	}

	return answer;
}