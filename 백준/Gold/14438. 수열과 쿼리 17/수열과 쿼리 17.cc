#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

typedef long long ll;

int init(vector<int>& vs, vector<int>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = vs[start];

	int mid = (start + end) / 2;
	return tree[node] = min(init(vs, tree, node * 2, start, mid), init(vs, tree, node * 2 + 1, mid + 1, end));
}

int query(vector<int>& vs, vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end ||
		right < start)
		return INT_MAX;

	if (left <= start &&
		end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return min(query(vs, tree, node * 2, start, mid, left, right), query(vs, tree, node * 2 + 1, mid + 1, end, left, right));
}

int update(vector<int>& vs, vector<int>& tree, int node, int start, int end, int idx, int val)
{
	if (idx < start ||
		idx > end)
		return tree[node];

	if (start == end)
		return tree[node] = val;

	int mid = (start + end) / 2;
	return tree[node] = min(update(vs, tree, node * 2, start, mid, idx, val), update(vs, tree, node * 2 + 1, mid + 1, end, idx, val));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> vs(n);
	vector<int> tree(n * 4,INT_MAX);
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}

	init(vs, tree, 1, 0, n - 1);

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
			update(vs, tree, 1, 0, n - 1, b, c);
		}
		else
		{
			c--;
			cout << query(vs, tree, 1, 0, n - 1, b, c) << '\n';
		}
	}

	return 0;
}