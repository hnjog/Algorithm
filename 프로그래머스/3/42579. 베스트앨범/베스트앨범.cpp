#include <string>
#include <vector>
#include<map>
#include <queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		if (a.first == b.first)
			return a.second > b.second;

		return a.first < b.first;
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	// 1. vector에 pair로 string과 장르별 sum을 담기
	// 2. map에는 string과 우선순위 큐를 담기
	// 3. vector 를 sum 기준으로 정렬
	// 4. vector의 반복문을 돌며 map에 저장해둔 우선순위 큐에서 가능한 2개씩 빼기
	// 5. 뺀 녀석들의 index를 answer에 담아주기

	map<string, int> m1;
	map <string, priority_queue<pii, vector<pii>, Compare>> m2;

	int gS = static_cast<int>(genres.size());

	for (int i = 0; i < gS; i++)
	{
		if (m2.find(genres[i]) == m2.end())
		{
			m1[genres[i]] = 0;
			m2[genres[i]] = priority_queue<pii, vector<pii>, Compare>();
		}

		m1[genres[i]] += plays[i];
		m2[genres[i]].push(make_pair(plays[i], i));
	}

	vector<pair<string, int>> vec(m1.begin(), m1.end());
	sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a.second > b.second; });

	for (int i = 0; i < vec.size(); i++)
	{
		int tempSize = m2[vec[i].first].size();
		for (int j = 0; j < tempSize; j++)
		{
			if (j >= 2)
				break;

			int ind = m2[vec[i].first].top().second;
			m2[vec[i].first].pop();

			answer.push_back(ind);
		}
	}

	return answer;
}