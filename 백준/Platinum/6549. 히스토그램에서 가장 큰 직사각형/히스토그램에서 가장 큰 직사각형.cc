#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

typedef long long ll;

ll getValue(vector<int>& v)
{
	stack<pair<ll, ll>> st;

	st.push({ v[0],0 });

	ll ret = 0;
	for (int i = 1; i < v.size(); i++)
	{
		ll nowH = v[i];
		ll idx = i;

		while(st.empty() == false &&
			nowH < st.top().first)
		{
			ll prevH = st.top().first;
			ll prevIdx = st.top().second;

			ll val = (i - prevIdx) * prevH;
			ret = max(ret, val);

			idx = prevIdx;

			st.pop();
		}

		st.push({ nowH,idx });
	}

	ll nowIdx = v.size();
	while (st.empty() == false)
	{
		ll prevH = st.top().first;
		ll prevIdx = st.top().second;

		ll val = (nowIdx - prevIdx) * prevH;
		ret = max(ret, val);

		st.pop();
	}

	return ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;

		vector<int> v;

		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			v.push_back(t);
		}

		cout << getValue(v) << '\n';
	}
}