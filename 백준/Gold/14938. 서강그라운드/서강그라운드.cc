#include<iostream>
#include<vector>	

using namespace std;

int main()
{
	// 플로이드 워셜을 통해
	// 모든 지역 기반 거리를 구해놓고
	// 특정한 시작점에서 m 거리 내부의 아이템 수를 더하여 총 값을 max값과 비교하는 방식으로

	int n, m, r;
	cin >> n >> m >> r;

	vector<int> items(n);
	for (int i = 0; i < n; i++)
		cin >> items[i];

	const int cant = 16;
	vector<vector<int>> weights(n,vector<int>(n,cant));

	for (int i = 0; i < n; i++)
		weights[i][i] = 0;

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		a--;
		b--;

		weights[a][b] = min(weights[a][b],l);
		weights[b][a] = min(weights[b][a],l);
	}

	// 플로이드 워셜
	// w[i][j] = min(w[i][j], w[i][k] + w[k][j])
	//
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);
			}
		}
	}

	int maxItem = 0;

	// max 값 찾기
	for (int start = 0; start < n; start++)
	{
		int sum = items[start];

		for (int i = 0; i < n; i++)
		{
			if (i == start)
				continue;

			if (m < weights[start][i])
				continue;

			sum += items[i];
		}

		if (sum > maxItem)
			maxItem = sum;
	}

	cout << maxItem;

	return 0;
}