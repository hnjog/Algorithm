#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int init(vector<int>& arr, vector<int>& tree,int node, int start, int end, bool bMax)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	if (bMax)
		return tree[node] = max(init(arr, tree, node * 2, start, mid, bMax), init(arr, tree, node * 2 + 1, mid + 1, end, bMax));

	return tree[node] = min(init(arr, tree, node * 2, start, mid, bMax), init(arr, tree, node * 2 + 1, mid + 1, end, bMax));
}

int query(vector<int>& arr, vector<int>& tree, int node, int start, int end, bool bMax, int left, int right)
{
	if (left > end || right < start)
	{
		if (bMax)
			return INT_MIN;
		return INT_MAX;
	}

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	if(bMax)
		return max(query(arr, tree, node * 2, start, mid, bMax,left,right), query(arr, tree, node * 2 + 1, mid + 1, end, bMax, left, right));

	return min(query(arr, tree, node * 2, start, mid, bMax, left, right), query(arr, tree, node * 2 + 1, mid + 1, end, bMax, left, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	vector<int> treeMax(n * 4), treeMin(n * 4);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	init(arr, treeMax, 1, 0, n - 1, true);
	init(arr, treeMin, 1, 0, n - 1, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;

		cout << query(arr, treeMin, 1, 0, n - 1, false, a, b) << ' ';
		cout << query(arr, treeMax, 1, 0, n - 1, true, a, b) << '\n';
	}

	return 0;
}