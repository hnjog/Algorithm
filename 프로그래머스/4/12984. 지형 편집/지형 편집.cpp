#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

long long solution(vector<vector<int> > land, int P, int Q) {
	vector<int> heights;
	// 현재 높이 이전의 모든 높이 합, 현재 높이 이후의 모든 높이 합
	long long preCount = 0, posCount = 0;

	// 현재 높이로 맞추기 위해 더해야하는 블록 수, 빼야 하는 블록 수
	long long preBlock = 0, posBlock = 0;
	
	for (const auto& lVec : land)
	{
		for (const auto& l : lVec)
		{
			heights.push_back(l);
			// 처음에 posCount에 다 넣어줌
			posCount += l;
		}
	}
	sort(heights.begin(), heights.end());

	const int hSize = heights.size();

	// 하나밖에 없거나,
	// 정렬 후의 처음과 끝이 같다면 계산할 필요가 없음
	if (hSize == 1 ||
		heights[hSize - 1] == heights[0])
		return 0;

	long long answer = LLONG_MAX;

	for (int i = 0; i < hSize; i++)
	{
		// 현재 높이 이전의 높이들의 총합을 preCount에 추가
		if (i > 0)
		{
			preCount += heights[i - 1];
		}

		// 현재 높이를 posCount에서 빼줌
		posCount -= heights[i];

		// preBlock: 현재 높이로 블록을 맞추기 위해 더해야 하는 블록의 수
		// 현재 높이 : heights[i]
		// 거기에 이전 블록들의 수인 i를 곱하며
		// 이전 블록 높이의 총합을 빼주어
		// '추가해야하는 블록 개수' 를 구한다
		preBlock = i * heights[i] - preCount;

		// posBlock: 현재 높이로 블록을 맞추기 위해 빼야 하는 블록의 수
		// (hSize - 1 - i) : 현재 높이 이후, 남은 높이의 개수 (i시점에서 남은 블록 수)
		posBlock = posCount - (hSize - 1 - i) * heights[i];

		// 현재 높이에서의 비용을 계산하고 최소 비용을 업데이트
		answer = min(answer, preBlock * P + posBlock * Q);
	}

	return answer;
}