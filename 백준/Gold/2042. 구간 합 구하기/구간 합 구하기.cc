#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

ll initRecur(vector<ll>& arr, vector<ll>& tree, ll node, ll start, ll end)
{
	if (start == end)
		return tree[node] = arr[start];

	ll mid = (start + end) / 2;
	return tree[node] = initRecur(arr, tree, node * 2, start, mid) + initRecur(arr, tree, node * 2 + 1, mid + 1,end);
}

void init(vector<ll>& arr, vector<ll>& tree)
{
	initRecur(arr, tree, 1, 0, arr.size() - 1);
}

ll queryRecur(vector<ll>& arr, vector<ll>& tree, ll node, ll start, ll end, ll left, ll right)
{
	if (left > end ||
		right < start)
		return 0;

	if (left <= start &&
		end <= right)
		return tree[node];

	ll mid = (start + end) / 2;
	return queryRecur(arr, tree, node * 2, start, mid,left,right) + queryRecur(arr, tree, node * 2 + 1, mid + 1, end,left,right);
}

ll query(vector<ll>& arr, vector<ll>& tree, ll left, ll right)
{
	return queryRecur(arr, tree, 1, 0, arr.size() - 1, left, right);
}

void updateRecur(vector<ll>& arr, vector<ll>& tree, ll node, ll start, ll end, ll idx, ll diff)
{
	if (idx < start || idx > end)
		return;

	tree[node] += diff;

	if (start == end)
		return;

	ll mid = (start + end) / 2;
	updateRecur(arr, tree, node * 2, start, mid, idx, diff);
	updateRecur(arr, tree, node * 2 + 1, mid + 1, end, idx, diff);
}

void update(vector<ll>& arr, vector<ll>& tree, ll idx, ll diff)
{
	updateRecur(arr, tree, 1, 0, arr.size() - 1, idx, diff);
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
	{
		cin >> arr[i];
	}

	init(arr, tree);

	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			b--;
			ll diff = c - arr[b];
			arr[b] = c;
			update(arr, tree, b, diff);
		}
		else
		{
			b--;
			c--;
			cout << query(arr, tree, b, c) << '\n';
		}
	}

	return 0;
}