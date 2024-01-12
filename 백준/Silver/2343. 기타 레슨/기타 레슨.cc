#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// n : 총 강의 수
	// m : 총 블루레이 수 (나눌 집합의 수)
	int n, m;
	cin >> n >> m;

	vector<int> nums;
	nums.reserve(n);

	int temp;
	ull high = 0, low = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		high += temp;
		if (temp > low)
		{
			low = temp;
		}
		nums.push_back(temp);
	}

	// 정렬된 값이 들어온다는 보장 x
	// 또한 순서가 유지되어야 함 (내가 정렬하면 안된다)
	// 이진 탐색을 하려면 결국 '찾는 기준'이 존재해야 함
	// 찾는 기준을 통하여 그 값보다 아래라면 아래쪽 범위를 탐색
	// 아니라면 위쪽 범위를 탐색한다
	// 일단 만약 m이 1이라면 '모든 강의 길이의 합'이 될 것
	// 그리고 m이 n과 같다면, '모든 강의 길이 중 가장 긴 녀석'이 될 것
	// 
	// 유의해야 할 점
	// 결국 구해야 하는 것은 '블루레이'의 길이이다
	// 모든 수의 합 : high
	// 모든 강의 중 가장 길이가 긴 녀석 : low
	// 1부터 9까지의 강의라면
	// high = 45, low = 9
	// mid 는 이 두 합의 중간이므로, 27
	// 그렇다면 왼쪽부터 27의 크기를 넘지 않도록
	// 숫자를 더해나가며
	// 합해서 넘을 것 같다면 블루레이의 '개수'를 늘려준다
	// 그렇게 끝까지 돌았을 때,
	// 개수가 m과 맞는지를 비교하고
	// m과 맞다면 종료
	// 개수가 m보다 작은 경우, 현재 '큰' 크기를 잡은 것이므로
	// mid가 high가 되고 다시 탐색
	// 개수가 m보다 많은 경우, 현재 '작은'크기를 잡은 것이므로
	// mid가 low가 되고 다시 탐색

	int count = 0;
	ull sum = 0;

	if (m == 1)
	{
		cout << high;
		return 0;
	}

	if (m == n)
	{
		cout << low;
		return 0;
	}

	while (true)
	{
		int mid = (high + low) / 2;

		for (int i = 0; i < n; i++)
		{
			if (sum + nums[i] > mid)
			{
				count++;
				sum = nums[i];
			}
			else
			{
				sum += nums[i];
			}
		}

		// 아직 남아있는 값이 있어서
		// 블루레이를 하나 더 써야 한다
		if (sum != 0)
		{
			count++;
		}

		// 개수보다 많은 경우,
		// 현재 mid가 작단 뜻이므로
		// mid는 탐색하였으므로 각각 1을 더한다
		if (count > m)
		{
			low = mid + 1;
		}
		else
		{
			// count == m 가 같은 경우에도 반복하는데
			// 우리가 구하는 것은
			// '가장 작은 길이의' 블루레이 길이이므로
			// 단순히 개수가 같더라도 정답이 아닐 수 있음
			// 따라서 high의 값을 낮추어 범위를 좁혀나간다
			high = mid - 1;
		}

		// low가 high 보다 큰 경우
		// 루프를 종료
		// 범위를 최종적으로 줄여나갔다면
		// high의 값과 low의 값이 점점 가까워진다
		if (low > high)
		{
			break;
		}

		count = 0;
		sum = 0;
	}

	// 최종값이 low에 담긴다
	cout << low;

	return 0;
}