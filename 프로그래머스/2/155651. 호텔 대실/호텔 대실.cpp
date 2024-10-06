#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<vector<string>> book_time) {
	int answer = 1;

	vector<pair<int, int>> times;

	for (const auto& book : book_time)
	{
		int startTime = ((book[0][0] - '0') * 10 + (book[0][1] - '0')) * 60 + (book[0][3] - '0') * 10 + (book[0][4] - '0');
		int endTime = ((book[1][0] - '0') * 10 + (book[1][1] - '0')) * 60 + (book[1][3] - '0') * 10 + (book[1][4] - '0');

		times.push_back({ startTime, endTime + 10 });
	}

	sort(times.begin(), times.end(), [](const auto& a, const auto& b)
		{
			if (a.first == b.first)
				return a.second > b.second;

			return a.first < b.first;
		});

	priority_queue<int, vector<int>, less<int>> pq;
	pq.push(times[0].second);

	for (int i = 1; i < times.size(); i++)
	{
		int startTime = times[i].first;
		int endTime = times[i].second;

		if (answer < pq.size())
			answer = pq.size();

		vector<int> temp;
		while (pq.empty() == false)
		{
			int lastTime = pq.top();
			pq.pop();
			if (lastTime > startTime)
			{
				temp.push_back(lastTime);
			}
		}

		for (int i = 0; i < temp.size(); i++)
		{
			pq.push(temp[i]);
		}

		pq.push(endTime);
	}

	if (answer < pq.size())
		answer = pq.size();

	return answer;
}