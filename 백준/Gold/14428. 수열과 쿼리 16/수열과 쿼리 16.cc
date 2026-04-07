#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int initRecur(vector<int>& vs, vector<int>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = start;

	int mid = (start + end) / 2;
	int i1 = initRecur(vs, tree, node * 2, start, mid);
	int i2 = initRecur(vs, tree, node * 2 + 1, mid + 1, end);

	int v1 = (i1 != INT_MAX) ? vs[i1] : INT_MAX;
	int v2 = (i2 != INT_MAX) ? vs[i2] : INT_MAX;

	if (v1 < v2)
	{
		return tree[node] = i1;
	}
	else if (v2 < v1)
	{
		return tree[node] = i2;
	}

	return tree[node] = min(i1, i2);
}

void init(vector<int>& vs, vector<int>& tree)
{
	initRecur(vs, tree, 1, 0, vs.size() - 1);
}

int queryRecur(vector<int>& vs, vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end ||
		right < start)
		return INT_MAX;

	if (left <= start &&
		right >= end)
		return tree[node];

	int mid = (start + end) / 2;

	int i1 = queryRecur(vs, tree, node * 2, start, mid, left, right);
	int i2 = queryRecur(vs, tree, node * 2 + 1, mid + 1, end, left, right);

	int v1 = (i1 != INT_MAX) ? vs[i1] : INT_MAX;
	int v2 = (i2 != INT_MAX) ? vs[i2] : INT_MAX;

	if (v1 < v2)
	{
		return i1;
	}
	else if (v2 < v1)
	{
		return i2;
	}

	return min(i1, i2);
}

int query(vector<int>& vs, vector<int>& tree,int left, int right)
{
	return queryRecur(vs, tree, 1, 0, vs.size() - 1, left, right);
}

int updateRecur(vector<int>& vs, vector<int>& tree, int node, int start, int end, int idx, int val)
{
	if (idx < start ||
		idx > end)
		return tree[node];

	if (start == end)
		return tree[node] = idx;

	int mid = (start + end) / 2;

	int i1 = updateRecur(vs, tree, node * 2, start, mid, idx, val);
	int i2 = updateRecur(vs, tree, node * 2 + 1, mid + 1, end, idx, val);

	int v1 = (i1 != INT_MAX) ? vs[i1] : INT_MAX;
	int v2 = (i2 != INT_MAX) ? vs[i2] : INT_MAX;

	if (v1 < v2)
	{
		return tree[node] = i1;
	}
	else if (v2 < v1)
	{
		return tree[node] = i2;
	}

	return tree[node] = min(i1, i2);
}

void update(vector<int>& vs, vector<int>& tree, int idx, int val)
{
	updateRecur(vs, tree, 1, 0, vs.size() - 1, idx, val);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> vs(n);
	vector<int> tree(n * 4, INT_MAX);

	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}

	init(vs, tree);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		b--;
		if (a == 1)
		{
			vs[b] = c;
			update(vs, tree, b, c);
		}
		else
		{
			c--;
			cout << query(vs, tree, b, c) + 1 << '\n';
		}
	}
}