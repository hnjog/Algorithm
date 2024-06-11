#include <vector>

using namespace std;

int solution(vector<int> a) {
	int n = a.size();

	if (n <= 2)
		return n;

	vector<int> leftMin(n), rightMin(n);

	// 해당 인덱스의 풍선을 기준으로
	// 왼쪽에서 가장 작은 값을 찾는다
	leftMin[0] = a[0];

	for (int i = 1; i < n; i++)
	{
		// 현재 시점과 비교하여 적어놓는다
		leftMin[i] = min(leftMin[i - 1], a[i]);
	}

	// 오른쪽에서 가장 작은값을 찾는다
	rightMin[n - 1] = a[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		rightMin[i] = min(rightMin[i + 1], a[i]);
	}

	// 양 끝
	int answer = 2; 

	for (int i = 1; i < n - 1; i++)
	{
		// i를 기준으로 (i 자신의 부분은 빼고)
		// 왼쪽에서 가장 작은 값과
		// 오른쪽에서 가장 작은 값을 비교한다
		// 가장 작은값이 a[i] 이상이라면 answer를 증가시킨다
		if (a[i] <= leftMin[i - 1] ||
			a[i] <= rightMin[i + 1])
		{
			answer++;
		}
	}

	return answer;
}