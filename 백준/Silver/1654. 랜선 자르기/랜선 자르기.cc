#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// 구해야 하는 것은 필요한 랜선의 개수 N을 만드는 최대의 길이

	int k, n;
	cin >> k >> n;

	vector<ull> lens;
	lens.reserve(k);

	ull temp;
	ull low = 1, high = 1;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		lens.push_back(temp);
		//if (temp < low)
		//{
		//	low = temp;
		//}

		if (temp > high)
		{
			high = temp;
		}
	}

	// 이진탐색으로 구해야 하는 것은 'n'의 최대 길이
	// 중요한 것은 'mid'를 구하는 방식이다
	// k == n 인 경우, lens 중 가장 작은 길이를 선택 (high)
	// n이 길어질 수록 low 값은 1에 근접해질 것으로 예측된다

	while (true)
	{
		ull cnt = 0;
		if (high < low)
		{
			// 최대 길이 이므로
			// high를 출력
			cout << high;
			break;
		}

		ull mid = (low + high) / 2;

		for (ull l : lens)
		{
			cnt += (l / mid);
		}

		if (cnt < n)
		{
			high = mid - 1;
		}
		else 
		{
			low = mid + 1;
		}
	}

	return 0;
}