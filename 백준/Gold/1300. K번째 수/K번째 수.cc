#include<iostream>
#include<math.h>

using namespace std;

typedef unsigned long long ull;

ull getCnt(ull _Mid, ull _N)
{
	ull ret = 0;

	for (ull i = 1; i <= _N; i++)
	{
		ret += min(_Mid / i, _N);
	}

	return ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	ull n, k;
	cin >> n >> k;

	ull low = 1, high = n * n;

	// low <= high일 때까지 루프
	// mid 값을 구한다
	// mid 보다 바로 작은 수 구하기 (이걸 cnt)
	// cnt가 k 보다 크거나 같다면 high = mid -1
	// cnt가 k보다 작다면 low = mid + 1
	// 이후 low 출력

	ull mid = 0, cnt = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		cnt = getCnt(mid, n);

		if (cnt >= k)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << low;

	return 0;
}