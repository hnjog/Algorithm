#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> pii;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		return a.second < b.second;
	}
};

int main()
{
	int n, k;
	cin >> n >> k;

	vector<pii> jewels(n);
	vector<ull> packs(k);

	for (int i = 0; i < n; i++)
	{
		cin >> jewels[i].first; // 무게
		cin >> jewels[i].second; // 가치
	}

	for (int i = 0; i < k; i++)
	{
		cin >> packs[i];
	}

	sort(jewels.begin(), jewels.end(), [](const pii& a, const pii& b)
		{
			return a.first < b.first;
		});

	sort(packs.begin(), packs.end());

	priority_queue<pii, vector<pii>, Compare> pq;

	ull sum = 0;
	int jIdx = 0;

	for (int i = 0; i < k; i++)
	{
		// 현재 가방 무게보다 작은 jewel들을 가치 기반 heap에 담는다
		while (jIdx < n &&
			jewels[jIdx].first <= packs[i])
		{
			pq.push(jewels[jIdx]);
			jIdx++;
		}

		if (pq.empty() == false)
		{
			sum += pq.top().second;
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}