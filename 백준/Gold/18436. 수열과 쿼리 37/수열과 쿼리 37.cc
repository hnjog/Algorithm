#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int init(vector<int>& arr, vector<int>& tree, int node, int start, int end, bool bOdd)
{
	if (start == end)
	{
		if ((bOdd && arr[start] % 2 == 1) ||
			(!bOdd && arr[start] % 2 == 0))
		{
			return tree[node] = 1;
		}

		return tree[node] = 0;
	}

	int mid = (start + end) / 2;
	return tree[node] = init(arr, tree, node * 2, start, mid, bOdd) + init(arr, tree, node * 2 + 1, mid + 1, end, bOdd);
}

int query(vector<int>& arr, vector<int>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(arr, tree, node * 2, start, mid, left, right) + query(arr, tree, node * 2 + 1, mid + 1, end, left, right);
}

int update(vector<int>& arr, vector<int>& tree, int node, int start, int end, int idx, bool bOdd)
{
	if (idx < start || idx > end)
		return tree[node];

	if (start == end)
	{
		if ((bOdd && arr[idx] % 2 == 1) ||
			(!bOdd && arr[idx] % 2 == 0))
		{
			return tree[node] = 1;
		}

		return tree[node] = 0;
	}

	int mid = (start + end) / 2;
	return tree[node] = update(arr, tree, node * 2, start, mid, idx, bOdd) + update(arr, tree, node * 2 + 1, mid + 1, end, idx, bOdd);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> treeOdd(n*4),treeEven(n*4);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	init(arr, treeOdd, 1, 0, n - 1, true);
	init(arr, treeEven, 1, 0, n - 1, false);

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;

		b--;
		if (a == 1)
		{
			arr[b] = c;

			update(arr, treeOdd, 1, 0, n - 1,b, true);
			update(arr, treeEven, 1, 0, n - 1,b, false);
		}
		else
		{
			c--;
			if (a == 2)
			{
				cout << query(arr, treeEven, 1, 0, n - 1, b, c) << '\n';
			}
			else
			{
				cout << query(arr, treeOdd, 1, 0, n - 1, b, c) << '\n';
			}
		}
	}

	return 0;
}