#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// 위상정렬
// degree를 이용하여
// 푸는 문제이며
// 
// 현재 degree가 0인 녀석을 먼저 빼네어
// 값을 완성시키면 됨
//

struct node
{
	int idx;
	int degree;
	vector<int> nextIdx;
};

vector<int> Func(vector<node>& nv)
{
	queue<node> q;
	for (auto& n : nv)
	{
		if (n.degree == 0)
			q.push(n);
	}

	vector<int> ret;

	while (q.empty() == false)
	{
		node& n = q.front();
		ret.push_back(n.idx + 1);

		for (int next : n.nextIdx)
		{
			nv[next].degree--;
			if (nv[next].degree == 0)
				q.push(nv[next]);
		}
		q.pop();
	}

	if (ret.size() < nv.size())
		ret = { 0 };

	return ret;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<node> nv(n);
	for (int i = 0; i < n; i++)
	{
		nv[i].idx = i;
		nv[i].degree = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;

		int prev = -1;
		for (int j = 0; j < t; j++)
		{
			int t2;
			cin >> t2;
			t2--;
			if (prev != -1)
			{
				nv[prev].nextIdx.push_back(t2);
				nv[t2].degree++;
			}
			prev = t2;
		}
	}

	vector<int> ret = Func(nv);

	for (int r : ret)
	{
		cout << r << '\n';
	}

	return 0;
}