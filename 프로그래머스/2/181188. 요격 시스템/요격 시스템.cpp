#include <vector>
#include<algorithm>

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

	sort(targets.begin(), targets.end());

	int tSize = targets.size();

	for (int i = 0; i < tSize - 1; i++)
	{
		bool beforeOverlap = isOverlap(targets[i],targets[i+1]);

		if (beforeOverlap)
		{
			targets[i + 1][0] = max(targets[i + 1][0], targets[i][0]);
			targets[i + 1][1] = min(targets[i + 1][1], targets[i][1]);
		}
		else
		{
			answer++;
		}
	}

	return answer;
}