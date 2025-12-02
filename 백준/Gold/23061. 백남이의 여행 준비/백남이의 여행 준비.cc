#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// 주어지는 가방 크기 와 가치들을 분석했을때 나오는 가치 효용성을 구하는 방식
	// 
	// - 가방에 넣은 총 가치 / 가방이 최대로 넣을 수 있는 크기 중 가장 큰 가방 선택
	// 
	// dp[i][j] : i번째 물품까지, j 무게로 얻을 수 있는 최대 가치
	// - 1차원 dp로 되는가를 고민해야 함
	//
	// dp[i] : i무게로 얻을 수 있는 최대 가치
	// (내림차순)
	// 
	// 이후, 각각의 가방에서 
	// dp[k1] / w1 이 방식으로 효용성이 제일 높은것을 선택하기
	//

	int n, m;
	cin >> n >> m;
	vector<int> weights,values;

	int maxWeight = 0;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		weights.push_back(w);
		values.push_back(v);

		maxWeight += w;
	}

	vector<int> packs(m);

	for (int i = 0; i < m; i++)
	{
		cin >> packs[i];
	}

	if (maxWeight > 1000000)
		maxWeight = 1000000;

	vector<int> dp(maxWeight + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int nowW = weights[i];
		int nowV = values[i];

		for (int j = maxWeight; j >= nowW; j--)
		{
			dp[j] = max(dp[j], dp[j - nowW] + nowV);
		}
	}

	// idx, 총 효율
	pair<int, double> ans;
	ans.first = 0;
	ans.second = 0.0;

	for (int i = 0; i < m; i++)
	{
		int w = packs[i];
		if (w > maxWeight)
			w = maxWeight;

		double v = dp[w] / (double)packs[i];

		if (ans.second < v)
		{
			ans.first = i;
			ans.second = v;
		}
	}

	cout << ans.first + 1;

	return 0;
}