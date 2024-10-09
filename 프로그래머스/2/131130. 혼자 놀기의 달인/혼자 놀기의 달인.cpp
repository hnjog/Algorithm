#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> cards) {
	int answer = 0;
	vector<bool> visit(cards.size(), false);
	priority_queue<int> pq;

	for (int i = 0; i < cards.size(); i++)
	{
		int count = 1;
		int start = i;

		if (visit[start])
			continue;

		visit[start] = true;
		int next = cards[i] - 1;

		while (next != start)
		{
			visit[next] = true;
			next = cards[next] - 1;
			count++;
		}

		pq.push(count);
	}

	if (pq.size() == 1)
		return 0;

	answer = pq.top();
	pq.pop();
	answer *= pq.top();

	return answer;
}