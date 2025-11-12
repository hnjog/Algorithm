#include<iostream>
#include<vector>

using namespace std;

struct fInfo
{
	int p;
	int val;
	int weight;
};

int FindParent(vector<fInfo>& pv, int x)
{
	if (pv[x].p == x)
		return x;

	return pv[x].p = FindParent(pv, pv[x].p);
}

bool Union(vector<fInfo>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a].p = b;
	pv[b].val += pv[a].val;
	pv[b].weight += pv[a].weight;
	pv[a].val = 0;
	pv[a].weight = 0;

	return true;
}

int Knapsack(const vector<int>& weights, const vector<int>& values, int k)
{
	vector<int> dp(k + 1, 0);

	int wSize = weights.size();

	for (int i = 0; i < wSize; i++)
	{
		// 총 용량을 k부터 시작하고
		// 현재 무게의 물건을 담을 수 있는지를 체크
		for (int j = k; j >= weights[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
		}
	}

	return dp[k];
}

int main()
{
	// 특정 아이들이 연결되어 있음
	// (친구의 친구들의 사탕들을 모두 강제로 빼앗기에)
	// 
	// 그렇기에 어떤 녀석의 사탕을 뺏으면
	// 총 사탕을 얼마 뺐는지를 알 수 있으면 좋을듯?
	// 
	// 1 2 3 이 친구이고
	// 4 5 6 이 각각의 사탕이라면
	// 
	// 1 2 3 중 한명만 골라도 전부 visit 처리와 함께
	// 15 개의 사탕 획득
	// 
	// - 차라리 처음에 모든 녀석들을 분리 집합으로 구분하여
	// 
	// {사탕 개수, 인원수} 이걸로 묶은 후
	// dp를 통해 k만큼 배낭문제로 푸는게 아닐까?

	int n, m, k;
	cin >> n >> m >> k;
	k--;

	vector<fInfo> pv(n);

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		pv[i].p = i;
		pv[i].val = c;
		pv[i].weight = 1;
	}

	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		Union(pv, t1, t2);
	}

	vector<int> weights, values;
	for (fInfo& f : pv)
	{
		if (f.val != 0)
		{
			weights.push_back(f.weight);
			values.push_back(f.val);
		}
	}

	cout << Knapsack(weights, values, k);

	return 0;
}