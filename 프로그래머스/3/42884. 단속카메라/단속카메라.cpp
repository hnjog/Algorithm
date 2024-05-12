#include <string>
#include <vector>
#include <queue>
#include<algorithm>
#include<math.h>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;

	sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
		if (a[0] == b[0])
			return a[1] < b[1];

		return a[0] < b[0];
		});

	queue<vector<int>> q;

	for (auto a : routes)
	{
		q.push(a);
	}
	
	while (q.size() > 1)
	{
		vector<int> line1 = q.front();
		q.pop();
		vector<int>& line2 = q.front();

		bool isOverlap = false;

		if (line1[0] == line2[0])
		{
			isOverlap = true;
		}
		else if (line1[1] >= line2[0])
		{
			isOverlap = true;
		}

		if (isOverlap)
		{
			line2[0] = max(line1[0], line2[0]);
			line2[1] = min(line1[1], line2[1]);
		}
		else
		{
			answer++;
		}
	}

	return answer;
}