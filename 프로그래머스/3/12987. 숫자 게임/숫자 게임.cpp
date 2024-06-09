#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	queue<int> bq;
	for (auto b : B)
	{
		bq.push(b);
	}

	int answer = 0;
	int aIndex = 0;

	while (bq.empty() == false)
	{
		int bt = bq.front();
		bq.pop();

		if (bt <= A[aIndex])
		{
			continue;
		}

		answer++;
		aIndex++;
	}

	return answer;
}