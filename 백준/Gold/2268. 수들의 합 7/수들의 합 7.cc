#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

ll query(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || start > right)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return query(arr, tree, node * 2, start, mid,left,right) + query(arr, tree, node * 2 + 1, mid + 1, end,left,right);
}

ll update(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int idx)
{
	if (idx < start || idx > end)
		return tree[node];

	if (start == end)
		return tree[node] = arr[idx];

	int mid = (start + end) / 2;
	return tree[node] = update(arr, tree, node * 2, start, mid, idx) + update(arr, tree, node * 2 + 1, mid + 1, end, idx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<ll> arr(n,0);
	vector<ll> tree(n * 4,0);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		b--;
		if (a == 0)
		{
			c--;

			if (b > c)
				swap(b, c);

			cout << query(arr, tree, 1, 0, n - 1, b, c) << '\n';
		}
		else
		{
			arr[b] = c;
			update(arr, tree, 1, 0, n - 1, b);
		}
	}

	return 0;
}