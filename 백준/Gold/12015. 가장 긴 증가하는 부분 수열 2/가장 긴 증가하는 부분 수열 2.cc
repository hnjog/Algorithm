#include <iostream>
#include <vector>

using namespace std;

int FindLikeValue(vector<int>& arr, int v)
{
	int left = 0;
	int right = arr.size() - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == v)
		{
			return mid;
		}

		if (arr[mid] > v)
			right = mid;
		else
			left = mid + 1;
	}

	return right;
}

int main(void)
{
	/*
		lcs 배열을 만들되
		하나씩 증가하면서 제작

		정답 배열
		n번째가 n-1 번째 보다 크다면
		정답 배열에 추가

		아니라면
		정답 배열 내부를 이분 탐색하여
		가장 가까우면서 큰 녀석과 교체
	*/

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> ret;
	ret.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > ret.back())
		{
			ret.push_back(arr[i]);
		}
		else
		{
			// 이진 탐색으로 가장 비슷한 값에 대입
			int idx = FindLikeValue(ret, arr[i]);
			ret[idx] = arr[i];
		}
	}

	cout << ret.size();

	return 0;
}