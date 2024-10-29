#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

bool isOverlap(vector<int>& a, vector<int>& b)
{
	if ((a[0] <= b[0] && a[1] > b[0]) ||
		(b[0] <= a[0] && b[1] > a[0]))
		return true;

	return false;
}

int solution(vector<vector<int>> targets) {
	int answer = 1;

	sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
		if (a[0] == b[0])
			return a[1] < b[1];

		return a[0] < b[0];
		});

	int tSize = targets.size();

	queue<vector<int>>q;

	for (auto a : targets)
	{
		q.push(a);
	}

	while (q.size() > 1)
	{
		vector<int> l1 = q.front();
		q.pop();
		vector<int>& l2 = q.front();

		bool overlap = isOverlap(l1,l2);

		if (overlap)
		{
			l2[0] = max(l1[0], l2[0]);
			l2[1] = min(l1[1], l2[1]);
		}
		else
		{
			answer++;
		}

	}
	
	return answer;
}