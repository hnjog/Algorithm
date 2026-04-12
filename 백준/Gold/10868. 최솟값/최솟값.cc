#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

int query(vector<int>& arr, vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return INT_MAX;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return min(query(arr, tree, node * 2, start, mid,left,right), query(arr, tree, node * 2 + 1, mid + 1, end,left,right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	vector<int> tree(n * 4);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;

		cout << query(arr, tree, 1, 0, n - 1, a, b) << '\n';
	}

	return 0;
}