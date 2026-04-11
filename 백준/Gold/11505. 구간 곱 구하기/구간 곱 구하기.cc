#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const ll dv = 1000000007;

ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = (init(arr, tree, node * 2, start, mid) % dv) * (init(arr, tree, node * 2 + 1, mid + 1, end) % dv) % dv;
}

ll query(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return ((query(arr, tree, node * 2, start, mid, left, right) % dv) * (query(arr, tree, node * 2 + 1, mid + 1, end, left, right) % dv)) % dv;
}

ll update(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int idx)
{
	if (idx < start || idx > end)
		return tree[node];

	if (start == end)
		return tree[node] = arr[idx];

	int mid = (start + end) / 2;
	return tree[node] = (update(arr, tree, node * 2, start, mid, idx) % dv) * (update(arr, tree, node * 2 + 1, mid + 1, end, idx) % dv) % dv;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> arr(n);
	vector<ll> tree(n * 4);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);

	for (int i = 0; i < m + k;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		b--;
		if (a == 1)
		{
			arr[b] = c;
			update(arr, tree, 1, 0, n - 1, b);
		}
		else
		{
			c--;
			cout << query(arr, tree, 1, 0, n - 1, b, c) << '\n';
		}
	}

	return 0;
}