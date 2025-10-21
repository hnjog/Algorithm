#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	int idx;
	int degree;
	vector<int> next;
};

struct Compare
{
	bool operator()(const node& a, const node& b)
	{
		if (a.degree == b.degree)
			return a.idx > b.idx;

		return a.degree < b.degree;
	}
};

int n, m;

void Topo(vector<node>& nVec)
{
	priority_queue<node, vector<node>, Compare> pq;
	for (node& n : nVec)
	{
		if (n.degree == 0)
			pq.push(n);
	}

	while (pq.empty() == false)
	{
		node n = pq.top();
		pq.pop();

		cout << n.idx + 1 << ' ';

		for (int next : n.next)
		{
			nVec[next].degree--;
			if (nVec[next].degree == 0)
				pq.push(nVec[next]);
		}
	}
}

int main()
{
	cin >> n >> m;

	vector<node> nVec(n);
	for (int i = 0; i < n; i++)
	{
		nVec[i].idx = i;
		nVec[i].degree = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int s, t;
		cin >> s >> t;
		s--;
		t--;
		nVec[s].next.push_back(t);
		nVec[t].degree++;
	}

	Topo(nVec);

	return 0;
}